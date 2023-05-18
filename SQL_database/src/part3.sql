--------------------------------------------------------------------------------------------------------------
--3.1
CREATE OR REPLACE FUNCTION transferred_points_table()
    RETURNS TABLE
                (
                    "Peer1"         VARCHAR,
                    "Peer2"         VARCHAR,
                    "PointsAmount"  BIGINT
                )
AS
$$
BEGIN
    RETURN QUERY (SELECT m."CheckingPeer", m."CheckedPeer", SUM(points)::BIGINT AS PointsAmount
            	FROM(
					(
					SELECT t1."CheckingPeer", t1."CheckedPeer", t1."PointsAmount" AS points
					FROM TransferredPoints AS t1
					)
					UNION
					(
					SELECT t2."CheckedPeer", t2."CheckingPeer", -t2."PointsAmount" AS points
				 	FROM TransferredPoints AS t2
				  	)
				) AS m
				GROUP BY 1, 2);
END;
$$ LANGUAGE plpgsql;
--TESTS--
SELECT *
FROM transferred_points_table();

--DROP FUNCTION transferred_points_table(); --DON'T DROP BEFORE CHECKING 3.5
--------------------------------------------------------------------------------------------------------------
--3.2
CREATE OR REPLACE FUNCTION peer_task_xp()
    RETURNS TABLE 
                (
                    Peer 	VARCHAR,
                    Task 	VARCHAR,
                    XP 		BIGINT
                )
AS
$$
BEGIN
    RETURN QUERY    (SELECT P."CheckingPeer" AS Peer, C."Task" AS Task, X."XPAmount" AS XP
				    FROM P2P AS P
					JOIN Checks AS C ON P."Check" = C."ID"
					JOIN XP AS X ON C."ID" = X."Check"
					JOIN Verter AS V ON C."ID" = V."Check"
					WHERE P."State" = 'Success'
						AND V."State" = 'Success' OR V."State" IS NULL
		 			ORDER BY 1,2,3);
END;
$$ LANGUAGE plpgsql;
--TESTS--
SELECT *
FROM peer_task_xp();

--SELECT * FROM Checks;
--SELECT * FROM P2P;
--SELECT * FROM XP;
--DROP FUNCTION peer_task_xp();
--------------------------------------------------------------------------------------------------------------
--3.3
CREATE OR REPLACE FUNCTION TimeTracking_Peer(IN d DATE)
    RETURNS TABLE
                (
                    "Peer" VARCHAR
                )
AS
$$
BEGIN
	RETURN QUERY    ((SELECT TimeTracking."Peer"
				    FROM TimeTracking
				    WHERE TimeTracking."State" = 1 AND "Date" = d
				    )
				    EXCEPT ALL
				    (
				    SELECT TimeTracking."Peer"
				    FROM TimeTracking
				    WHERE TimeTracking."State" = 2 AND "Date" = d
				    ));
END;
$$ LANGUAGE plpgsql;
--TESTS--
SELECT *
FROM TimeTracking_Peer('2022-12-21');

--SELECT * FROM TimeTracking;
--DROP FUNCTION TimeTracking_Peer();
--------------------------------------------------------------------------------------------------------------
--3.4
CREATE TABLE IF NOT EXISTS "Output"
                    (
                        "Peer"          VARCHAR,
                        "PointsChange"  BIGINT
                    );

CREATE OR REPLACE PROCEDURE calculate_points()
AS
$$
DECLARE
        "peer_name" VARCHAR;
        "points_change" BIGINT;
BEGIN
        FOR "peer_name" IN
            SELECT DISTINCT "CheckingPeer" FROM TransferredPoints
            UNION
            SELECT DISTINCT "CheckedPeer" FROM TransferredPoints
        LOOP
            SELECT
                SUM(CASE WHEN "CheckingPeer" = "peer_name" THEN "PointsAmount" ELSE 0 END)
                - SUM(CASE WHEN "CheckedPeer" = "peer_name" THEN "PointsAmount" ELSE 0 END)
            INTO "points_change"
            FROM TransferredPoints;
            --RAISE NOTICE '%,%', "peer_name", "points_change"; -- FOR TESTS
		    INSERT INTO "Output" VALUES("peer_name", "points_change");
        END LOOP;
END;
$$ LANGUAGE plpgsql;
--TESTS--
CALL calculate_points();

SELECT *
FROM "Output"
ORDER BY 2 DESC;

--DROP PROCEDURE calculate_points();
--DELETE FROM "Output";
--DROP TABLE "Output";
--------------------------------------------------------------------------------------------------------------
--3.5
CREATE TABLE IF NOT EXISTS "Output2"
                                    (
                                        "Peer"          VARCHAR,
                                        "PointsChange"  BIGINT
                                    );

CREATE OR REPLACE PROCEDURE calculate_points_version_2()
AS
$$
DECLARE
        "peer_name" VARCHAR;
        "points_change" BIGINT;
BEGIN
	    FOR "peer_name" IN
            SELECT DISTINCT "Peer1" FROM transferred_points_table()
	    LOOP
		    SELECT
			    SUM(CASE WHEN "Peer1" = "peer_name" THEN "PointsAmount" ELSE 0 END)
		    INTO "points_change"
		    FROM transferred_points_table();
		    --RAISE NOTICE '%,%', "peer_name", "points_change"; -- FOR TESTS
		    INSERT INTO "Output2" VALUES("peer_name", "points_change");
	    END LOOP;
END;
$$ LANGUAGE plpgsql;
--TESTS--
CALL calculate_points_version_2();

SELECT *
FROM "Output2"
ORDER BY 2 DESC, 1;

--DROP PROCEDURE calculate_points_version_2();
--DELETE FROM "Output2";
--DROP TABLE "Output2";
--------------------------------------------------------------------------------------------------------------
--3.6
CREATE OR REPLACE FUNCTION most_checked_task_for_each_day()
    RETURNS TABLE
                (
                    "Day"  DATE,
                    "Task" VARCHAR
                )
AS
$$
BEGIN
	RETURN QUERY (WITH CTE AS   (SELECT Checks."Date" AS "Day", Checks."Task" AS "Task", COUNT(*) AS "counter"
					            FROM Checks
					            GROUP BY 1, 2),
			          CTE2 AS   (SELECT CTE."Day", MAX("counter") AS "Days"
					            FROM CTE
					            GROUP BY 1)
		SELECT CTE."Day", CTE."Task"
		FROM CTE
		JOIN CTE2 ON CTE."Day" = CTE2."Day" AND CTE."counter" = CTE2."Days"
		ORDER BY 1);
END;
$$ LANGUAGE plpgsql;
--TESTS--
SELECT * 
FROM most_checked_task_for_each_day();

--DROP FUNCTION most_checked_task_for_each_day();
--------------------------------------------------------------------------------------------------------------
--3.7
CREATE OR REPLACE FUNCTION block_end("block_name" VARCHAR)
    RETURNS TABLE
                (
                    "Peers"  VARCHAR,
                    "Day"    DATE
                )
AS
$$
BEGIN
    RETURN QUERY    (SELECT DISTINCT "Peer", "Date"
                    FROM Checks
                    JOIN P2P P ON Checks."ID" = P."Check"
                    LEFT JOIN Verter AS V ON Checks."ID" = V."Check"
                    WHERE (V."State" = 'Success' OR V."State" IS NULL AND P."State" = 'Success')
                        AND "Task" =    (SELECT MAX("Title")
                                        FROM Tasks
                                        WHERE "Title" SIMILAR TO CONCAT("block_name", '[0-9]%')));
END;
$$ LANGUAGE plpgsql;
--TESTS--
SELECT *
FROM block_end('C');

--DROP FUNCTION block_end(block_name varchar);
--------------------------------------------------------------------------------------------------------------
--3.8
CREATE OR REPLACE FUNCTION best_peer()
    RETURNS TABLE
                (
                    Peer            VARCHAR,
                    RecommendedPeer VARCHAR
                )
AS
$$
BEGIN
    RETURN QUERY
        WITH tmp   AS   (SELECT p."Nickname", f."Peer1", f."Peer2", r."RecommendedPeer"
                        FROM Peers p
                        JOIN Friends f ON p."Nickname" IN (f."Peer1", f."Peer2")
                        JOIN Recommendations r ON r."Peer" IN (f."Peer1", f."Peer2")
                            AND p."Nickname" != r."Peer"
                            AND p."Nickname" != r."RecommendedPeer"),

             tmp1  AS   (SELECT "Nickname", "RecommendedPeer", COUNT(*) AS count
                        FROM tmp
                        GROUP BY "Nickname", "RecommendedPeer"),

             tmp2  AS   (SELECT "Nickname", MAX(count) AS max_count
                        FROM tmp1
                        GROUP BY "Nickname")

        SELECT t1."Nickname", t1."RecommendedPeer"
        FROM tmp1 t1
        JOIN tmp2 t2 ON t1."Nickname" = t2."Nickname" AND t1.count = t2.max_count;
END;
$$ LANGUAGE plpgsql;
--TESTS--
SELECT *
FROM best_peer();

--DROP FUNCTION best_peer();
--------------------------------------------------------------------------------------------------------------
--3.9
CREATE OR REPLACE FUNCTION block_completion_percentage("block1" VARCHAR, "block2" VARCHAR)
    RETURNS TABLE
                (
                    "StartedBlock1"         NUMERIC,
                    "StartedBlock2"         NUMERIC,
                    "StartedBothBlocks"     NUMERIC,
                    "DidntStartAnyBlock"    NUMERIC
                )
AS
$$
DECLARE
    "block1_prefix" VARCHAR := "block1" || '%';
    "block2_prefix" VARCHAR := "block2" || '%';
    "all_peers" BIGINT;
BEGIN
    all_peers := (SELECT count("Nickname") FROM Peers);
    RETURN QUERY
                    WITH block1_users AS        (SELECT DISTINCT "Peer"
                                                FROM Checks
                                                WHERE "Task" LIKE block1_prefix
                                                ),

                         block2_users AS        (SELECT DISTINCT "Peer"
                                                FROM Checks
                                                WHERE "Task" LIKE block2_prefix
                                                ),

                        both_blocks_users AS    (SELECT "Peer"
                                                FROM block1_users
                                                INTERSECT
                                                SELECT "Peer"
                                                FROM block2_users
                                                ),

                        neither_block_users AS  (SELECT "Nickname" AS "Peer"
                                                FROM Peers
                                                EXCEPT
                                                (SELECT "Peer"
                                                FROM block1_users
                                                UNION DISTINCT
                                                SELECT "Peer"
                                                FROM block2_users)
                                                )

    SELECT (SELECT count("Peer") FROM block1_users)::numeric/all_peers*100 ,
           (SELECT count("Peer") FROM block2_users)::numeric/all_peers*100,
           (SELECT count("Peer") FROM both_blocks_users)::numeric/all_peers*100,
           (SELECT count("Peer") FROM neither_block_users)::numeric/all_peers*100;
END
$$ LANGUAGE plpgsql;
--TESTS--
SELECT *
FROM block_completion_percentage('C', 'D');

--DROP FUNCTION block_completion_percentage(block1 VARCHAR, block2 VARCHAR);
--------------------------------------------------------------------------------------------------------------
--3.10
CREATE OR REPLACE FUNCTION birthday_check()
    RETURNS TABLE
                (
                    "SuccessfulChecks"      INT,
                    "UnsuccessfulChecks"    INT
                )
AS
$$
BEGIN
	RETURN QUERY    (WITH counts AS     (SELECT COUNT(Checks."Peer")
								 	    FILTER (WHERE P2P."State" = 'Success') AS success,
				    			        COUNT(Checks."Peer")
                           			    FILTER (WHERE P2P."State"= 'Success') AS fail
                    			        FROM Checks
								        LEFT JOIN Peers ON Checks."Peer" = Peers."Nickname"
                             	        JOIN P2P ON Checks."ID" = P2P."Check"
                   				        WHERE (EXTRACT(MONTH FROM Checks."Date") = EXTRACT(MONTH FROM Peers."Birthday"))
                                            AND (EXTRACT(DAY FROM Checks."Date") = EXTRACT(DAY FROM Peers."Birthday")))
    	
        SELECT  (success::NUMERIC / NULLIF(success + fail, 0)::NUMERIC *100)::INT AS SuccessfulChecks,
                (fail::NUMERIC / NULLIF(success + fail, 0)::NUMERIC * 100)::INT AS UnsuccessfulChecks
		FROM counts);
END;
$$ LANGUAGE plpgsql;
--TESTS--
SELECT *
FROM birthday_check();

--DROP FUNCTION birthday_check();
--------------------------------------------------------------------------------------------------------------
--3.11
CREATE OR REPLACE FUNCTION peer_two_ok_one_not(task1 VARCHAR, task2 VARCHAR, task3 VARCHAR)
    RETURNS TABLE
                (
                    peer VARCHAR
                )
AS
$$
BEGIN
    RETURN QUERY (WITH tmp AS   (SELECT Checks."ID" AS tmp_id,
                                        p."State" AS pstate,
                                        p."Check" AS pcheck,
                                        Checks."Task" AS task,
                                        Checks."Peer" AS peer,
                                        v."State" AS vstate
                                FROM Checks
                                JOIN P2P P ON Checks."ID" = P."Check"
                                FULL JOIN Verter V ON Checks."ID" = V."Check"
                                WHERE P."State" <> 'Start'
                                    AND v."State" <> 'Start'
                                    AND (v."State" = 'Success' OR v."State" IS NULL AND p."State" = 'Success')),

                       t1  AS   (SELECT *
                                FROM tmp
                                WHERE task = task1),

                       t2  AS   (SELECT *
                                FROM tmp
                                WHERE task = task2),

                       t3  AS   (SELECT *
                                FROM tmp
                                WHERE task = task3)

        SELECT t1.peer
        FROM t1
        JOIN t2 ON t1.peer = t2.peer
        LEFT JOIN t3 ON t1.peer = t3.peer
        WHERE t3.tmp_id IS NULL);
END;
$$ LANGUAGE plpgsql
    IMMUTABLE;
--TESTS--
SELECT *
FROM peer_two_ok_one_not('C2_SimpleBashUtils', 'C3_s21_string+', 'C5_s21_decimal');

--DROP FUNCTION peer_two_ok_one_not();
--------------------------------------------------------------------------------------------------------------
--3.12
CREATE OR REPLACE FUNCTION prev_number()
    RETURNS TABLE
                (
                    title  VARCHAR,
                    number INTEGER
                )
AS
$$
BEGIN
    RETURN QUERY    (WITH RECURSIVE CTE AS  (SELECT "Title", "ParentTask", 0 AS counter
                                            FROM Tasks
                                            WHERE "ParentTask" IS NULL
                                            UNION ALL
                                            SELECT tasks."Title", tasks."ParentTask", counter + 1
                                            FROM Tasks
                                            JOIN CTE ON CTE."Title" = tasks."ParentTask")
                  
        SELECT "Title", counter
        FROM CTE);
END;
$$ LANGUAGE plpgsql;
--TESTS--
SELECT *
FROM prev_number();

--DROP FUNCTION prev_number();
--------------------------------------------------------------------------------------------------------------
--3.13
CREATE OR REPLACE FUNCTION good_days(IN n integer)
    RETURNS  TABLE
                (
                    dt DATE
                )
AS
$$
BEGIN
    RETURN QUERY    WITH RECURSIVE CTE AS   (SELECT "Date",
                                            (SELECT "Time" 
                                            FROM P2P 
                                            WHERE Checks."ID" = P2P."Check" AND P2P."State" = 'Start') tm,
                                            (CASE
                                                WHEN p."State" = 'Success' AND (v."ID" IS NULL OR v."State" = 'Success') AND "XPAmount" >= 0.8 * "MaxXP" THEN 'Success'
                                                WHEN p."State" = 'Failure' OR v."State" = 'Failure' OR "XPAmount" < 0.8 * "MaxXP" THEN 'Failure'
                                            END)                                                                           status
                                            FROM Checks
                                            LEFT JOIN P2P p ON Checks."ID" = p."Check"
                                            LEFT JOIN Verter v ON Checks."ID" = v."Check"
                                            JOIN Tasks t ON t."Title" = Checks."Task"
                                            JOIN XP x ON Checks."ID" = x."Check"
                                            WHERE p."State" != 'Start'
                                                AND (v."State" != 'Start' or v."ID" isnull)
                                            ORDER BY 1, 2
                                            ),

                                   CTE2 AS  (SELECT *,
                                            ROW_NUMBER() OVER (PARTITION BY "Date" ORDER BY "Date", tm) AS row_num
                                            FROM CTE
                                            ),

                                   CTE3 AS  (SELECT "Date", tm, status, row_num,
                                            (CASE WHEN status = 'Success' THEN 1
                                                ELSE 0 END ) as counter
                                            FROM CTE2
                                            WHERE row_num = 1
                                            UNION ALL
                                            SELECT CTE2."Date", CTE2.tm, CTE2.status, CTE2.row_num, (
                                            CASE WHEN CTE2.status = 'Success' THEN counter + 1
                                                ELSE 0 END )
                                            FROM CTE2
                                            JOIN CTE3 ON CTE2."Date" = CTE3."Date" AND CTE2.row_num = CTE3.row_num + 1
                                            )
    SELECT "Date"
    FROM CTE3
    WHERE counter = n;
END;
$$ LANGUAGE plpgsql;
--TESTS--
SELECT *
FROM good_days(3);

--DROP FUNCTION good_days();
--------------------------------------------------------------------------------------------------------------
--3.14
CREATE OR REPLACE FUNCTION peer_xp()
    RETURNS TABLE
                (
                    "Peer" VARCHAR,
                    "XP"   NUMERIC
                )
AS
$$
BEGIN
    RETURN QUERY    (WITH tmp AS    (SELECT Checks."Peer", MAX(XP."XPAmount") AS px
                                    FROM Checks
                                    JOIN XP ON Checks."ID" = XP."Check"
                                    GROUP BY Checks."Peer", "Task")

    SELECT tmp."Peer", SUM(px)
    FROM tmp
    GROUP BY tmp."Peer"
    ORDER BY SUM(px) DESC);
END;
$$ LANGUAGE plpgsql;
--TESTS--
SELECT *
FROM peer_xp();

--DROP FUNCTION peer_xp();
--------------------------------------------------------------------------------------------------------------
--3.15
CREATE OR REPLACE FUNCTION early_coming("ttime" TIME, "n" BIGINT)
    RETURNS TABLE
                (
                    "Peers" VARCHAR
                )
AS
$$
BEGIN
    RETURN QUERY   (SELECT T."Peer"
                    FROM TimeTracking AS T
                    WHERE T."State" = 1 AND T."Time" < "ttime"
                    GROUP BY T."Peer"
                    HAVING COUNT(T."Peer") >= "n"
                    );
END;
$$ LANGUAGE plpgsql;
--TESTS--
SELECT *
FROM early_coming('12:00:00', 1);

--DROP FUNCTION early_coming();
--------------------------------------------------------------------------------------------------------------
--3.16
CREATE OR REPLACE FUNCTION out_campus("out_days" BIGINT, "out_times" BIGINT)
    RETURNS TABLE
                (
                    "Peers" VARCHAR
                )
AS
$$
BEGIN
    RETURN QUERY (WITH tmp AS  (SELECT T."Peer", T."Date", COUNT(*) AS "count_p"
                                FROM TimeTracking AS T
                                WHERE "Date" >= CURRENT_DATE - ("out_days" || ' days')::INTERVAL
                                GROUP BY T."Peer", T."Date")
                  SELECT "Peer"
                  FROM tmp
                  GROUP BY "Peer", "count_p"
                  HAVING "count_p" > "out_times");
END;
$$ LANGUAGE plpgsql;
--TESTS--
SELECT *
FROM out_campus(1000, 2);

--DROP FUNCTION out_campus();
--------------------------------------------------------------------------------------------------------------
--3.17
CREATE OR REPLACE FUNCTION procent_enter()
	RETURNS TABLE
                (
                    "Month"         TEXT,
                    "EarlyEntries"  NUMERIC
                )
AS
$$
BEGIN
	RETURN QUERY    (WITH monthly_visits AS    (SELECT date_trunc('month', tt."Date") AS "month",
											    COUNT(*)  AS total_visits,
											    COUNT(*) FILTER (WHERE EXTRACT(hour FROM tt."Time") < 12) AS early_visits
											    FROM TimeTracking AS tt
											    JOIN Peers p ON tt."Peer" = p."Nickname" AND EXTRACT("month" FROM p."Birthday") = EXTRACT("month" FROM tt."Date")
										        WHERE tt."State" = 1
											    GROUP BY date_trunc('month', tt."Date")
                                                )

	SELECT to_char(monthly_visits.month, 'Month') AS "Month", round(100.0 * monthly_visits.early_visits / monthly_visits.total_visits, 2) AS "EarlyEntries"
	FROM monthly_visits);
	END;
$$ LANGUAGE plpgsql;
--TESTS--
SELECT *
FROM procent_enter();

--DROP FUNCTION procent_enter();
--------------------------------------------------------------------------------------------------------------
