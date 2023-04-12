SHOW TRANSACTION ISOLATION LEVEL; --Session1
SHOW TRANSACTION ISOLATION LEVEL; --Session2

SELECT * FROM pizzeria WHERE name  = 'Pizza Hut'; --Session1
SELECT * FROM pizzeria WHERE name  = 'Pizza Hut'; --Session2

COMMIT WORK; --Session1
COMMIT WORK; --Session2

SELECT * FROM pizzeria WHERE name  = 'Pizza Hut'; --Session1
SELECT * FROM pizzeria WHERE name  = 'Pizza Hut'; --Session2