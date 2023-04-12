INSERT INTO person_discounts
SELECT ROW_NUMBER( ) OVER ( ) AS id,
 person_id,
 pizzeria_id,
 CASE WHEN COUNT(*) = 1 THEN 10.5
  WHEN COUNT (*) = 2 THEN 22
  ELSE 30
  END discount
FROM person_order
JOIN menu ON person_order.menu_id = menu.id
INNER JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
GROUP BY 2, 3
ORDER BY 2;
