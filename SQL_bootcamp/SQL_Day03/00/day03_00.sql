SELECT menu.pizza_name, menu.price, pizzeria.name AS pizzeria_name, person_visits.visit_date
FROM person
JOIN person_visits ON person.id = person_visits.person_id
JOIN pizzeria ON person_visits.pizzeria_id = pizzeria.id
JOIN menu ON pizzeria.id = menu.pizzeria_id
WHERE person.name = 'Kate' AND menu.price >= 800 AND menu.price <= 1000
ORDER BY 1, 2, 3;
