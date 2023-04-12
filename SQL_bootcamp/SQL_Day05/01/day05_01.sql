SET enable_indexscan = ON;
SET enable_seqscan = FALSE;
EXPLAIN ANALYZE 
SELECT m.pizza_name, pizzeria.name AS pizzeria_name
FROM menu AS m
JOIN pizzeria ON m.pizzeria_id = pizzeria.id
