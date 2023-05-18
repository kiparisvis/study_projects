--------------------------------------------------------------------------------------------------------------
--2.1
CREATE OR REPLACE PROCEDURE AddCheck(IN peer VARCHAR, IN CheckingPeer VARCHAR, IN TaskTitle VARCHAR, IN State checkstatus, IN time_ TIME WITHOUT TIME ZONE) AS $$
    DECLARE
        save BIGINT;
    BEGIN
        save := 0;
       IF State = 'Start' THEN
                save := (SELECT MAX("ID") + 1 FROM checks);
                INSERT INTO checks("ID", "Peer", "Task")
                VALUES (save, peer, TaskTitle);
        END IF;
        INSERT into p2p ("ID", "Check", "CheckingPeer", "State", "Time")
        VALUES((SELECT MAX("ID") + 1 FROM p2p),
               (CASE
                   WHEN save != 0 THEN save
                   ELSE (SELECT "Check" FROM p2p JOIN checks c on c."ID" = p2p."Check" JOIN tasks t on t."Title" = c."Task" WHERE "CheckingPeer" = CheckingPeer AND c."Peer" = peer AND t."Title" = TaskTitle)
                END),
               CheckingPeer,
               State,
               time_);
    END;
$$ LANGUAGE plpgsql;
--TESTS--
CALL AddCheck('romainez', 'medaelis', 'C2_SimpleBashUtils', 'Start', '21:02:00');
CALL AddCheck('romainez', 'medaelis', 'C2_SimpleBashUtils', 'Success', '21:40:00');

SELECT * FROM P2P;

--DROP PROCEDURE AddCheck;
--------------------------------------------------------------------------------------------------------------
--2.2
CREATE OR REPLACE PROCEDURE AddVerter(IN peer VARCHAR, IN TaskTitle VARCHAR, IN State checkstatus, IN time_ TIME WITHOUT TIME ZONE) AS $$
    BEGIN
        INSERT INTO Verter ("ID", "Check", "State", "Time")
        VALUES((SELECT MAX("ID") + 1 FROM Verter),
               (SELECT Checks."ID" FROM Checks JOIN Tasks t ON t."Title" = Checks."Task" JOIN P2P p ON Checks."ID" = p."Check" WHERE "Peer" = peer AND t."Title" = TaskTitle AND p."State" = 'Success'
                                                                                                                        ORDER BY p."Time" DESC LIMIT 1),
               State,
               time_);
    END
$$ LANGUAGE plpgsql;
--TESTS--
CALL AddVerter('romainez', 'C2_SimpleBashUtils', 'Start', '21:02:00');
CALL AddVerter('romainez', 'C2_SimpleBashUtils', 'Failure', '21:02:00');

SELECT * FROM Verter;

--DROP PROCEDURE AddVerter;
--------------------------------------------------------------------------------------------------------------
--2.3
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
--TESTS--
INSERT INTO Checks VALUES (25, 'maryamgr', 'C5_s21_decimal', '2022-11-02');
INSERT INTO TransferredPoints VALUES (9, 'romainez', 'maryamgr', 1);--After insert TransferredPoints."PointsAmount" = 1


INSERT INTO P2P VALUES (49, 25, 'romainez', 'Start', '11:11:11');--After insert TransferredPoints."PointsAmount" will be updated to 2

SELECT * FROM TransferredPoints;

--DELETE FROM P2P WHERE P2P."Time" = '11:11:11';
--DELETE FROM TransferredPoints WHERE TransferredPoints."ID" = 9;
--DELETE FROM Checks WHERE Checks."ID" = 25;

--DROP FUNCTION update_transferred_points() CASCADE;
--------------------------------------------------------------------------------------------------------------
--2.4
CREATE OR REPLACE FUNCTION insert_XP_fnc() RETURNS TRIGGER AS $$
BEGIN
    CASE WHEN
        NEW."XPAmount" <= (SELECT "MaxXP" FROM Tasks JOIN checks c ON tasks."Title" = c."Task" WHERE c."ID" = NEW."Check") AND
        NEW."Check" in (SELECT P2P."Check" FROM P2P FULL JOIN Verter V ON P2P."Check" = V."Check" WHERE P2P."State" = 'Success' AND (V."State" = 'Success' OR V."State" ISNULL))
        THEN
        RETURN NEW;
        ELSE
        RETURN NULL;
        END CASE;
END
$$
LANGUAGE plpgsql;

CREATE TRIGGER insert_XP
    BEFORE INSERT ON xp
    FOR EACH ROW
    EXECUTE FUNCTION
    insert_XP_fnc();
--TESTS--
INSERT INTO XP VALUES (20, 3, 500); -- max XP is 350
SELECT * FROM XP;

INSERT INTO XP VALUES (20, 2, 100); -- max XP is 750, but P2P failed
SELECT * FROM XP;

INSERT INTO XP VALUES (20, 3, 300); -- Ok
SELECT * FROM XP;
--------------------------------------------------------------------------------------------------------------
