CREATE VIEW v_price_with_discount AS (SELECT person.name, menu.pizza_name, menu.price, ROUND(menu.price - (menu.price * 0.1))::integer AS discount_price
FROM person
JOIN person_order ON person.id = person_order.person_id
JOIN menu ON person_order.menu_id = menu.id
ORDER BY 1, 2);
