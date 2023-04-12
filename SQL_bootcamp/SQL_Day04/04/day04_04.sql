CREATE VIEW v_symmetric_union AS (SELECT person_visits.person_id
FROM person_visits
WHERE person_visits.visit_date = '2022-01-02'
UNION
SELECT person_visits.person_id
FROM person_visits
WHERE person_visits.visit_date = '2022-01-06'
ORDER BY 1);
