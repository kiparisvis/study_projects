WITH female AS (SELECT pizzeria.name
			 FROM pizzeria
			 JOIN menu ON pizzeria.id = menu.pizzeria_id
			 JOIN person_order ON menu.id = person_order.menu_id
			 JOIN person ON person_order.person_id = person.id 
			 WHERE person.gender = 'female' AND person.gender != 'male'),
	male AS (SELECT pizzeria.name
			 FROM pizzeria
			 JOIN menu ON pizzeria.id = menu.pizzeria_id
			 JOIN person_order ON menu.id = person_order.menu_id
			 JOIN person ON person_order.person_id = person.id 
			 WHERE person.gender = 'male' AND person.gender != 'female')
(
SELECT female.name AS pizzeria_name
FROM female
EXCEPT
SELECT male.name AS pizzeria_name
FROM male
 )
UNION
(
SELECT male.name AS pizzeria_name
FROM male
EXCEPT
SELECT female.name AS pizzeria_name
FROM female
)
ORDER BY 1;
