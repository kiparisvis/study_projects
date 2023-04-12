BEGIN TRANSACTION ISOLATION LEVEL SERIALIZABLE; --Session1
BEGIN TRANSACTION ISOLATION LEVEL SERIALIZABLE; --Session2

SELECT * FROM pizzeria; --Session1

UPDATE pizzeria SET rating = 3.0 WHERE name = 'Pizza Hut'; --Session2
COMMIT WORK; --Session2

SELECT * FROM pizzeria;	--Session1
COMMIT WORK; --Session1
SELECT * FROM pizzeria; --Session1

SELECT * FROM pizzeria; --Session2
