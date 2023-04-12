BEGIN TRANSACTION ISOLATION LEVEL REPEATABLE READ; --Session1
BEGIN TRANSACTION ISOLATION LEVEL REPEATABLE READ; --Session2

SELECT SUM(rating) FROM pizzeria; --Session1

UPDATE pizzeria SET rating = 5 WHERE name = 'Pizza Hut'; --Session2
COMMIT WORK; --Session2

SELECT SUM(rating) FROM pizzeria; --Session1
COMMIT WORK; --Session1
SELECT SUM(rating) FROM pizzeria; --Session1

SELECT SUM(rating) FROM pizzeria; --Session2
