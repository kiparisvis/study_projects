WITH female AS (SELECT pizzeria.name
			 FROM pizzeria
			 JOIN person_visits ON pizzeria.id = person_visits.pizzeria_id
			 JOIN person ON person_visits.person_id = person.id
			 WHERE person.gender = 'female' AND person.gender != 'male'),
	male AS (SELECT pizzeria.name
			 FROM pizzeria
			 JOIN person_visits ON pizzeria.id = person_visits.pizzeria_id
			 JOIN person ON person_visits.person_id = person.id
			 WHERE person.gender = 'male' AND person.gender != 'female')
(
SELECT female.name AS pizzeria_name
FROM female
EXCEPT ALL
SELECT male.name AS pizzeria_name
FROM male
 )
UNION ALL
(
SELECT male.name AS pizzeria_name
FROM male
EXCEPT ALL
SELECT female.name AS pizzeria_name
FROM female
)
ORDER BY 1;
