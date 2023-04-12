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
    (SELECT cost, paths FROM tour
    WHERE length(paths)=7 and end_point='a') AS rec
ORDER BY total_cost, tour;
