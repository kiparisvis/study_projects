--------------------------------------------------------------------------------------------------------------
-- Database creation
--YOU NEED TO CREATE DATABASE TEST;

CREATE TABLE IF NOT EXISTS Peers
( "Nickname" VARCHAR PRIMARY KEY NOT NULL,
  "Birthday" DATE NOT NULL
);

CREATE TABLE IF NOT EXISTS ChecksTasks
( "Title" VARCHAR PRIMARY KEY NOT NULL,
  "ParentTask" VARCHAR DEFAULT 'null',
  "MaxXP" BIGINT NOT NULL,
  CONSTRAINT fk_Tasks_ParentTask_Tasks_Title FOREIGN KEY ("ParentTask") REFERENCES ChecksTasks("Title")
);

CREATE TABLE IF NOT EXISTS Checks
( "ID" BIGINT PRIMARY KEY NOT NULL,
  "Peer" VARCHAR NOT NULL,
  "Task" VARCHAR NOT NULL,
  "Date" DATE NOT NULL DEFAULT current_date,
  CONSTRAINT fk_Checks_Peer_Peers_Nickname FOREIGN KEY ("Peer") REFERENCES Peers("Nickname"),
  CONSTRAINT fk_Checks_Task_Tasks_Title FOREIGN KEY ("Task") REFERENCES ChecksTasks("Title")
);

 CREATE TABLE IF NOT EXISTS P2P
 ( "ID" BIGINT PRIMARY KEY NOT NULL,
   "Check" BIGINT NOT NULL,
   "CheckingPeer" VARCHAR NOT NULL,
   "State" VARCHAR NOT NULL,
   "Time" TIME(0) WITHOUT TIME ZONE NOT NULL,
   CONSTRAINT fk_P2P_Check_Checks_ID FOREIGN KEY ("Check") REFERENCES Checks("ID"),
   CONSTRAINT fk_P2P_CheckingPeer_Peers_Nickname FOREIGN KEY ("CheckingPeer") REFERENCES Peers("Nickname"),
   CONSTRAINT unique_CheckingPeer_CheckID_Status UNIQUE ("CheckingPeer", "Check", "State")
 );

CREATE TABLE IF NOT EXISTS Verter
( "ID" BIGINT PRIMARY KEY NOT NULL,
  "Check" BIGINT NOT NULL,
  "State" VARCHAR NOT NULL,
  "Time" time NOT NULL,
  CONSTRAINT fk_Verter_Check_Checks_ID FOREIGN KEY ("Check") REFERENCES Checks("ID")
);

CREATE TABLE IF NOT EXISTS TransferredPoints
( "ID" BIGINT PRIMARY KEY NOT NULL,
  "CheckingPeer" VARCHAR NOT NULL,
  "CheckedPeer" VARCHAR NOT NULL,
  "PointsAmount" BIGINT NOT NULL,
  CONSTRAINT fk_TransferredPoints_CheckingPeer_Peers_Nickname FOREIGN KEY ("CheckingPeer") REFERENCES Peers("Nickname"),
  CONSTRAINT fk_TransferredPoints_CheckedPeer_Peers_Nickname FOREIGN KEY ("CheckedPeer") REFERENCES Peers("Nickname")
);

CREATE TABLE IF NOT EXISTS Friends
( "ID" BIGINT PRIMARY KEY NOT NULL,
  "Peer1" VARCHAR NOT NULL,
  "Peer2" VARCHAR NOT NULL,
  CONSTRAINT fk_Friends_Peer1_Peers_Nickname FOREIGN KEY ("Peer1") REFERENCES Peers("Nickname"),
  CONSTRAINT fk_Friends_Peer2_Peers_Nickname FOREIGN KEY ("Peer2") REFERENCES Peers("Nickname")
);

CREATE TABLE IF NOT EXISTS Recommendations
( "ID" BIGINT PRIMARY KEY NOT NULL,
  "Peer" VARCHAR NOT NULL,
  "RecommendedPeer" VARCHAR,
  CONSTRAINT fk_Recommendations_Peer_Peers_Nickname FOREIGN KEY ("Peer") REFERENCES Peers("Nickname"),
  CONSTRAINT fk_Recommendations_RecommendedPeer_Peers_Nickname FOREIGN KEY ("RecommendedPeer") REFERENCES Peers("Nickname")
);

CREATE TABLE IF NOT EXISTS XP
( "ID" BIGINT PRIMARY KEY NOT NULL,
  "Check" BIGINT NOT NULL,
  "XPAmount" BIGINT NOT NULL,
  CONSTRAINT fk_XP_Check_Checks_Task FOREIGN KEY ("Check") REFERENCES Checks("ID")
);

CREATE TABLE IF NOT EXISTS TimeTracking
( "ID" BIGINT PRIMARY KEY NOT NULL,
  "Peer" VARCHAR NOT NULL,
  "Date" DATE NOT NULL DEFAULT current_date,
  "Time" TIME NOT NULL DEFAULT current_time,
  "State" BIGINT NOT NULL,
  CONSTRAINT fk_TimeTracking_Peer_Peers_Nickname FOREIGN KEY ("Peer") REFERENCES Peers("Nickname"),
  CONSTRAINT ch_TimeTracking check ( "State" in ('1','2') )
);
--------------------------------------------------------------------------------------------------------------
-- Create procedures of import and export
-- ATTENTION!!!! Replace the path with the current path
CREATE OR REPLACE PROCEDURE export(IN tablename varchar, IN path text, IN separator char) AS $$
    DECLARE
        cur_path text;
    BEGIN
        cur_path := '/Users/romainez/Desktop/SQL2_Info21_v1.0-1/src'; -- HERE
        EXECUTE format('COPY %s TO ''%s'' DELIMITER ''%s'' CSV HEADER;', tablename, cur_path || path, separator);
    END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE PROCEDURE import(IN tablename varchar, IN path text, IN separator char) AS $$
    DECLARE
         cur_path text;
    BEGIN
        cur_path := '/Users/romainez/Desktop/SQL2_Info21_v1.0-1/src'; -- AND HERE
        EXECUTE format('COPY %s FROM ''%s'' DELIMITER ''%s'' CSV HEADER;',
        tablename, cur_path || path, separator);
    END;
$$ LANGUAGE plpgsql;
--------------------------------------------------------------------------------------------------------------
CREATE OR REPLACE FUNCTION peer_task_xp()
    RETURNS TABLE 
                (
                    Peer VARCHAR,
                    Task VARCHAR,
                    XP BIGINT
                )
AS
$$
BEGIN
    RETURN QUERY    (SELECT P."CheckingPeer" AS Peer, C."Task" AS Task, X."XPAmount" AS XP
				    FROM P2P AS P
					JOIN Checks AS C ON P."Check" = C."ID"
					JOIN XP AS X ON C."ID" = X."Check"
					WHERE P."State" = 'Success'
		 			ORDER BY 1,2,3);
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION TimeTracking_Peer(IN d DATE)
    RETURNS TABLE
                (
                    "Peer" VARCHAR
                )
AS
$$
BEGIN
	RETURN QUERY ((SELECT TimeTracking."Peer"
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

CREATE OR REPLACE FUNCTION update_transferred_points()
RETURNS TRIGGER AS $$
DECLARE
"TMP" VARCHAR = (SELECT "Peer"
				FROM Checks
				WHERE "ID" = NEW."Check");
BEGIN
	CASE WHEN
	NEW."Check" IN (SELECT Checks."ID" FROM Checks) AND 
	NEW."CheckingPeer" IN (SELECT Peers."Nickname" FROM Peers)
	THEN
	UPDATE TransferredPoints
	SET "PointsAmount" = ("PointsAmount" + 1)
	WHERE "CheckedPeer" = "TMP" AND "CheckingPeer" = NEW."CheckingPeer";
    RETURN NEW;
	ELSE
	RETURN NULL;
	END CASE;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER update_transferred_points
AFTER INSERT ON P2P
FOR EACH ROW
WHEN (NEW."State" = 'Start')
EXECUTE FUNCTION update_transferred_points();

CREATE OR REPLACE FUNCTION insert_XP_fnc() RETURNS TRIGGER AS $$
BEGIN
    CASE WHEN
        NEW."XPAmount" <= (SELECT "MaxXP" FROM Tasks JOIN checks c on tasks."Title" = c."Task" WHERE c."ID" = NEW."Check") and
        NEW."Check" in (SELECT P2P."Check" FROM P2P FULL JOIN Verter V on P2P."Check" = V."Check" WHERE P2P."State" = 'Success' and (V."State" = 'Success' or V."State" ISNULL))
        THEN
        return NEW;
        ELSE
        return NULL;
        END CASE;
end
$$
LANGUAGE plpgsql;

CREATE TRIGGER insert_XP
    BEFORE INSERT ON xp
    FOR EACH ROW
    EXECUTE FUNCTION
    insert_XP_fnc();

--------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------
--4.1
CREATE OR REPLACE PROCEDURE delete_tables(IN table_name_in text)
LANGUAGE plpgsql
AS $$
DECLARE
    table_name text;
BEGIN
  FOR table_name IN SELECT tablename FROM pg_tables WHERE schemaname = 'public' AND tablename LIKE table_name_in || '%'
  LOOP
    EXECUTE format('DROP TABLE IF EXISTS %I CASCADE', table_name);
  END LOOP;
END;
$$;
--TESTS
CALL delete_tables('checks');--MUST TO DELETE TABLES Checks AND ChecksTasks
--------------------------------------------------------------------------------------------------------------
--4.2
CREATE OR REPLACE PROCEDURE get_scalar_functions(out count INT)
LANGUAGE plpgsql
AS $$
DECLARE
    func_rec RECORD;
BEGIN
    count := 0;
    FOR func_rec IN  SELECT routine_name name, string_agg(concat_ws(': ', parameter_name, data_type, parameter_mode), '; ') params FROM (SELECT routine_name, ordinal_position, parameter_name, parameter_mode, parameters.data_type
                     FROM information_schema.routines JOIN information_schema.parameters on routines.specific_name = parameters.specific_name
                     WHERE routines.routine_catalog=current_database() and routines.specific_schema = 'public' and routine_type = 'FUNCTION'
                     ORDER BY 1,2 ) res
                     GROUP BY routine_name
    LOOP
        count := count + 1;
        RAISE NOTICE 'Function: %(%)', func_rec.name, func_rec.params;
    end loop;
    RAISE NOTICE 'count: %', count;
END;
$$;
--TESTS--
DO $$
DECLARE
    counter INT := 0;
BEGIN
    CALL get_scalar_functions(counter);
END;
$$;
--------------------------------------------------------------------------------------------------------------
--4.3
CREATE OR REPLACE PROCEDURE drop_dml_triggers(OUT num_triggers_deleted INTEGER)
LANGUAGE plpgsql
AS $$
DECLARE
    rcd RECORD;
BEGIN
    num_triggers_deleted := 0;
    FOR rcd IN
        SELECT trigger_name, event_object_table
        FROM information_schema.triggers
        WHERE trigger_catalog = current_database()
          AND trigger_schema = 'public'
          AND event_manipulation IN ('INSERT', 'UPDATE', 'DELETE')
    LOOP
        EXECUTE format('DROP TRIGGER IF EXISTS %I ON %I CASCADE', rcd.trigger_name, rcd.event_object_table);
        num_triggers_deleted := num_triggers_deleted + 1;
    END LOOP;
    RAISE NOTICE 'count: %', num_triggers_deleted;
END
$$;
--TESTS--
DO $$
DECLARE
    counter INTEGER := 0;
BEGIN
    CALL drop_dml_triggers(counter);
END;
$$;

SELECT trigger_name
        FROM information_schema.triggers
        WHERE trigger_catalog = current_database()
          AND trigger_schema = 'public';--MUST BE EMPTY
--------------------------------------------------------------------------------------------------------------
--4.4
CREATE OR REPLACE PROCEDURE find_sql_text(IN search_text TEXT)
LANGUAGE plpgsql
AS $$
DECLARE
  rcd RECORD;
BEGIN
  FOR rcd IN
    SELECT routine_name, routine_type, data_type
    FROM information_schema.routines
    WHERE routines.routine_catalog=current_database() and routines.specific_schema = 'public' and (routine_name LIKE '%' || search_text || '%' or routine_definition LIKE '%' || search_text || '%')
  LOOP
    RAISE NOTICE 'Name: %, Type: %, Return type: %', rcd.routine_name, rcd.routine_type, rcd.data_type;
  END LOOP;
END;
$$;
--TESTS--
CALL find_sql_text('cur_path');
CALL find_sql_text('QWERTY');
--------------------------------------------------------------------------------------------------------------
