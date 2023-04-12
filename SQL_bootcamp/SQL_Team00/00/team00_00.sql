create table if not exists road
( point1 varchar not null,
  point2 varchar not null,
  cost integer not null
);

WITH CTE_m (point1, point2, cost) AS (
    SELECT 'a','b', 10 UNION ALL
    SELECT 'a','c', 15 UNION ALL
    SELECT 'a','d', 20 UNION ALL
    SELECT 'b','c', 35 UNION ALL
    SELECT 'b','d', 25 UNION ALL
    SELECT 'c','d', 30
), CTE (point1, point2, cost) AS (
     SELECT * FROM CTE_m
     UNION ALL
     SELECT point2, point1, cost FROM CTE_m
)
insert into road
SELECT * FROM CTE
WHERE NOT EXISTS(SELECT * FROM road);

WITH RECURSIVE tour (start_point, end_point, paths, cost) AS (
  SELECT
      point1, point2, 'a', cost
  FROM
      road
  WHERE point1='a'

  UNION ALL

  SELECT
      tour.end_point, point2, concat(tour.paths, ',', tour.end_point), road.cost + tour.cost
  FROM
      tour
  JOIN road ON tour.end_point=road.point1 AND position(road.point1 IN tour.paths) = 0
)
SELECT
    cost total_cost, concat('{', paths, ',a}') tour
FROM
    tour
WHERE length(paths)=7 and end_point='a' and cost = (SELECT min(cost) FROM tour WHERE length(paths)=7 and end_point='a')
ORDER BY total_cost, tour;
