SELECT pizzeria.name, COUNT(order_date) AS count_of_orders, ROUND(AVG(menu.price), 2)::REAL AS average_price, MAX(menu.price), MIN(menu.price)
FROM person_order 
JOIN menu ON person_order.menu_id = menu.id
JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
GROUP BY pizzeria.name
ORDER BY 1;
