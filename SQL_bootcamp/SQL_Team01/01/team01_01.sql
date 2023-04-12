-- Before running the request:
--insert into currency values (100, 'EUR', 0.85, '2022-01-01 13:29');
--insert into currency values (100, 'EUR', 0.79, '2022-01-08 13:29');

WITH closest_date AS (
    SELECT
        user_id,
        money,
        rate_to_usd,
        c.name,
        row_number() over (partition by b order by (b.updated::date >= c.updated::date) DESC, abs(b.updated::date - c.updated::date)) as dist
    FROM
        balance b
    JOIN currency c on c.id = b.currency_id
)
SELECT coalesce(u.name, 'not defined') AS name,
       coalesce(u.lastname, 'not defined') AS lastname,
       cd.name currency_name,
       (money * cd.rate_to_usd)::real currency_in_usd
FROM closest_date cd
FULL JOIN "user" u on cd.user_id=u.id
WHERE dist = 1
ORDER BY name DESC, lastname, currency_name;
