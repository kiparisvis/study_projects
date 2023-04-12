WITH visit AS (SELECT pizzeria.name
			  FROM pizzeria
			  JOIN person_visits ON pizzeria.id = person_visits.pizzeria_id
			  JOIN person ON person_visits.person_id = person.id
			  WHERE person.name = 'Andrey'),
	 p_order AS (SELECT pizzeria.name
			  FROM pizzeria
			  JOIN menu ON pizzeria.id = menu.pizzeria_id
			  JOIN person_order ON menu.id = person_order.menu_id
			  JOIN person ON person_order.person_id = person.id
			  WHERE person.name = 'Andrey')
(SELECT visit.name AS pizzeria_name
	   FROM visit)
EXCEPT ALL
(SELECT p_order.name AS pizzeria_name
	   FROM p_order);
