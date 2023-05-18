--------------------------------------------------------------------------------------------------------------
--Create tables
CREATE TABLE IF NOT EXISTS Peers
( "Nickname" VARCHAR PRIMARY KEY NOT NULL,
  "Birthday" DATE NOT NULL
);

CREATE TABLE IF NOT EXISTS Tasks
( "Title" VARCHAR PRIMARY KEY NOT NULL,
  "ParentTask" VARCHAR DEFAULT 'null',
  "MaxXP" BIGINT NOT NULL,
  CONSTRAINT fk_Tasks_ParentTask_Tasks_Title FOREIGN KEY ("ParentTask") REFERENCES Tasks("Title")
);
CREATE TYPE CheckStatus AS ENUM ('Start', 'Success', 'Failure');

CREATE TABLE IF NOT EXISTS Checks
( "ID" BIGINT PRIMARY KEY NOT NULL,
  "Peer" VARCHAR NOT NULL,
  "Task" VARCHAR NOT NULL,
  "Date" DATE NOT NULL DEFAULT current_date,
  CONSTRAINT fk_Checks_Peer_Peers_Nickname FOREIGN KEY ("Peer") REFERENCES Peers("Nickname"),
  CONSTRAINT fk_Checks_Task_Tasks_Title FOREIGN KEY ("Task") REFERENCES Tasks("Title")
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
CREATE OR REPLACE PROCEDURE export(IN tablename VARCHAR, IN path TEXT, IN separator CHAR) AS $$
    DECLARE
        cur_path TEXT;
    BEGIN
        cur_path := '/Users/romainez/Desktop/SQL2_Info21_v1.0-1/src'; -- HERE

        EXECUTE format('COPY %s TO ''%s'' DELIMITER ''%s'' CSV HEADER;', tablename, cur_path || path, separator);
    END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE PROCEDURE import(IN tablename VARCHAR, IN path TEXT, IN separator CHAR) AS $$
    DECLARE
         cur_path TEXT;
    BEGIN
        cur_path := '/Users/romainez/Desktop/SQL2_Info21_v1.0-1/src'; -- AND HERE

        EXECUTE format('COPY %s FROM ''%s'' DELIMITER ''%s'' CSV HEADER;',
        tablename, cur_path || path, separator);
    END;
$$ LANGUAGE plpgsql;
--------------------------------------------------------------------------------------------------------------
--import from CSV to DB
--export from DB to CSV
--------------------------------------------------------------------------------------------------------------
--Calls procedure of import for all tables
CALL import('Peers', '/csv/Peers.csv', ',');
CALL import('Tasks', '/csv/Tasks.csv', ',');
CALL import('Checks', '/csv/Checks.csv', ',');
CALL import('P2P', '/csv/P2P.csv', ',');
CALL import('Verter', '/csv/Verter.csv', ',');
CALL import('XP', '/csv/XP.csv', ',');
CALL import('TransferredPoints', '/csv/TransferredPoints.csv', ',');
CALL import('Friends', '/csv/Friends.csv', ',');
CALL import('Recommendations', '/csv/Recommendations.csv', ',');
CALL import('TimeTracking', '/csv/TimeTracking.csv', ',');
--------------------------------------------------------------------------------------------------------------
--Calls procedure of export for all tables
CALL export('Peers', '/csv/Peers.csv', ',');
CALL export('Tasks', '/csv/Tasks.csv', ',');
CALL export('Checks', '/csv/Checks.csv', ',');
CALL export('P2P', '/csv/P2P.csv', ',');
CALL export('Verter', '/csv/Verter.csv', ',');
CALL export('XP', '/csv/XP.csv', ',');
CALL export('TransferredPoints', '/csv/TransferredPoints.csv', ',');
CALL export('Friends', '/csv/Friends.csv', ',');
CALL export('Recommendations', '/csv/Recommendations.csv', ',');
CALL export('TimeTracking', '/csv/TimeTracking.csv', ',');
--------------------------------------------------------------------------------------------------------------
--For checking tables
 SELECT * FROM Peers;
 SELECT * FROM Tasks;
 SELECT * FROM Checks;
 SELECT * FROM P2P;
 SELECT * FROM Verter;
 SELECT * FROM XP;
 SELECT * FROM TransferredPoints;
 SELECT * FROM Friends;
 SELECT * FROM Recommendations;
 SELECT * FROM TimeTracking;
--------------------------------------------------------------------------------------------------------------
--Remove data from tables (sorted)
 DELETE FROM P2P;
 DELETE FROM Verter;
 DELETE FROM XP;
 DELETE FROM Checks;
 DELETE FROM TransferredPoints;
 DELETE FROM Friends;
 DELETE FROM Recommendations;
 DELETE FROM TimeTracking;
 DELETE FROM Peers;
 DELETE FROM Tasks;
--------------------------------------------------------------------------------------------------------------
--Remove tables
 DROP TABLE TimeTracking;
 DROP TABLE TransferredPoints;
 DROP TABLE Verter;
 DROP TABLE XP;
 DROP TABLE Recommendations;
 DROP TABLE Friends;
 DROP TABLE P2P;
 DROP TABLE Checks;
 DROP TABLE Tasks;
 DROP TABLE Peers;
 DROP TYPE CheckStatus CASCADE;
--------------------------------------------------------------------------------------------------------------
--Remove procedures
DROP PROCEDURE import;
DROP PROCEDURE export;
--------------------------------------------------------------------------------------------------------------
