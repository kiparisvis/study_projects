WITH pizzeria_info AS
    (SELECT pi.id AS pizzeria_id, 
    pi.name AS pizzeria_name, 
    menu.id AS product_id, 
    menu.pizza_name AS product_name FROM menu
    JOIN pizzeria pi ON menu.pizzeria_id = pi.id)

(SELECT pizzeria_name AS name, COUNT(order_date) AS count,
'order' AS action_type FROM pizzeria_info info
JOIN person_order ord ON ord.menu_id = info.product_id
GROUP BY name
ORDER BY count DESC
LIMIT 3)

UNION

(SELECT (SELECT DISTINCT pizzeria_name FROM pizzeria_info info WHERE info.pizzeria_id = pv.pizzeria_id) AS name,
    COUNT(visit_date) AS count,
    'visit' AS action_type FROM person_visits pv
    GROUP BY name
    ORDER BY count DESC
    LIMIT 3)

ORDER BY action_type ASC, count DESC;
