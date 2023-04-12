WITH base AS (
  SELECT person.name AS NAME,
               menu.pizza_name AS pizza_name,
               price,
               pizzeria.name AS pizzeria_name,
               person.id AS person_id, 
               pizzeria.id AS pizzeria_id
  FROM person_order
        JOIN menu ON menu.id = person_order.menu_id
        JOIN person ON person.id = person_order.person_id
        JOIN pizzeria ON pizzeria.id = menu.pizzeria_id)
SELECT name, 
       pizza_name, 
       price, 
       (price - price * (person_discounts.discount / 100)):: REAL AS discount_price,
       pizzeria_name
FROM base
JOIN person_discounts ON person_discounts.person_id = base.person_id
            AND person_discounts.pizzeria_id = base.pizzeria_id
ORDER BY name, pizza_name;
