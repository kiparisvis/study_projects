WITH pidor AS (SELECT person_order.menu_id --pizza_id_from_table_order
			 FROM person_order),
	 pid AS  (SELECT menu.pizzeria_id, menu.id, menu.pizza_name, menu.price --pizza_id_from_table_menu
			 FROM menu)
SELECT pid.pizza_name, pid.price, pizzeria.name AS pizzeria_name
FROM pid
JOIN pizzeria ON pid.pizzeria_id = pizzeria.id
WHERE pid.id NOT IN (SELECT pidor.menu_id
					FROM pidor)
ORDER BY 1, 2;
