WITH female AS (SELECT person.name, pizza_name
        FROM person
          JOIN person_order ON person_order.person_id = person.id
          JOIN menu ON menu.id = person_order.menu_id
            WHERE person.gender = 'female'
         )
SELECT female.name AS name
FROM female
WHERE female.pizza_name = 'pepperoni pizza'
INTERSECT
SELECT female.name
FROM female
WHERE female.pizza_name = 'cheese pizza'
ORDER BY name;
