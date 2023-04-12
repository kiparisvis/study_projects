INSERT INTO person_visits VALUES ((SELECT MAX(person_visits.id)+1 FROM person_visits),
								  (SELECT person.id
								   FROM person
								   WHERE person.name = 'Dmitriy'),
								  (SELECT pizzeria.id
								  FROM pizzeria
								  JOIN menu ON pizzeria.id = menu.pizzeria_id
								  WHERE pizzeria.name != 'Papa Johns' AND menu.price < 800
								  LIMIT 1),
								 '2022-01-08');

REFRESH MATERIALIZED VIEW mv_dmitriy_visits_and_eats;
