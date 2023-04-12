CREATE MATERIALIZED VIEW mv_dmitriy_visits_and_eats AS (SELECT pizzeria.name
FROM pizzeria
JOIN menu ON pizzeria.id = menu.pizzeria_id
JOIN person_visits ON menu.pizzeria_id = person_visits.pizzeria_id
JOIN person ON person_visits.person_id = person.id
WHERE person.name = 'Dmitriy' AND price < 800 AND person_visits.visit_date = '2022-01-08');
