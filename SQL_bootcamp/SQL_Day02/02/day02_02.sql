SELECT CASE WHEN person.name IS NULL THEN '-'
  	ELSE person.name
	END AS person_name,
	pv.visit_date,
  	CASE WHEN pizzeria.name IS NULL THEN '-'
  	ELSE pizzeria.name 
 	END AS pizzeria_name
FROM (SELECT * FROM person_visits WHERE person_visits.visit_date BETWEEN '2022-01-01' AND '2022-01-03') AS pv
FULL JOIN person ON pv.person_id = person.id
FULL JOIN pizzeria ON pv.pizzeria_id = pizzeria.id
ORDER BY 1, 2, 3;
