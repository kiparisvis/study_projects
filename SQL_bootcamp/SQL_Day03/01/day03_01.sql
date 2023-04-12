WITH pidr AS (SELECT person_order.menu_id
			 FROM person_order),
	 pid AS  (SELECT menu.id
			 FROM menu)
SELECT pid.id AS menu_id
FROM pid
WHERE pid.id NOT IN (SELECT pidr.menu_id
					FROM pidr)
ORDER BY 1;
