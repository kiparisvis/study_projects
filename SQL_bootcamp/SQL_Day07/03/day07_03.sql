WITH pizzeria_info AS 
 (SELECT pizzeria.id AS pizzeria_id,
    pizzeria.name AS pizzeria_name,
    menu.id AS product_id,
    menu.pizza_name AS product_name FROM menu
JOIN pizzeria ON menu.pizzeria_id = pizzeria.id),
counted_orders AS (SELECT pizzeria_name AS name,
    COUNT(order_date) AS count,
    'order' AS action_type FROM pizzeria_info info
JOIN person_order ON person_order.menu_id = info.product_id
GROUP BY name
ORDER BY count DESC),
counted_vizits AS (SELECT
    (SELECT DISTINCT pizzeria_name FROM pizzeria_info info WHERE info.pizzeria_id = person_visits.pizzeria_id) AS name,
    COUNT(visit_date) AS count,
    'visit' AS action_type FROM person_visits
GROUP BY name
ORDER BY count DESC)
SELECT pizzeria.name,
(CASE
    WHEN counted_orders.count IS NOT NULL AND counted_vizits.count IS NOT NULL THEN counted_orders.count + counted_vizits.count
    WHEN counted_orders.count IS NOT NULL AND counted_vizits.count IS NULL THEN counted_orders.count
    WHEN counted_orders.count IS  NULL AND counted_vizits.count IS NOT NULL THEN counted_vizits.count
    ELSE 0
END) AS total_count
FROM pizzeria
LEFT JOIN counted_orders ON pizzeria.name = counted_orders.name
LEFT JOIN counted_vizits ON counted_orders.name = counted_vizits.name
ORDER BY total_count DESC, name ASC;
