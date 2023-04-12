WITH first_t AS (SELECT menu.pizza_name, pizzeria.name, menu.price
				 FROM menu
				 JOIN pizzeria ON menu.pizzeria_id = pizzeria.id),
	 second_t AS (SELECT menu.pizza_name, pizzeria.name, menu.price
				 FROM menu
				 JOIN pizzeria ON menu.pizzeria_id = pizzeria.id)
SELECT DISTINCT first_t.pizza_name, first_t.name AS pizzeria_name_1, second_t.name AS pizzeria_name_2, first_t.price
FROM first_t
JOIN second_t ON first_t.price = second_t.price AND first_t.pizza_name = second_t.pizza_name
WHERE first_t.name != second_t.name AND first_t.name < second_t.name
ORDER BY pizza_name;