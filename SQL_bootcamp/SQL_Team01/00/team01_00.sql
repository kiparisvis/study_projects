WITH gbalance AS (
    SELECT user_id, type, currency_id, sum(money) AS volume
    FROM balance
    GROUP BY user_id, type, currency_id
	),
	guser AS (
	SELECT id, name, lastname
	FROM "user"
	),
    last_rate_by_id AS (
		SELECT id, max(updated) last
		FROM currency
		GROUP BY id
	),
	gcurrency AS (
		SELECT c.id, name,
			   rate_to_usd
		FROM currency c
		JOIN last_rate_by_id li ON c.id = li.id AND li.last = c.updated
	)
SELECT
    coalesce(guser.name, 'not defined') AS name,
    coalesce(guser.lastname, 'not defined') AS lastname,
    gbalance.type,
    gbalance.volume,
    coalesce(gcurrency.name, 'not defined') AS currency_name,
    coalesce(gcurrency.rate_to_usd, 1) last_rate_to_usd,
    (gbalance.volume * coalesce(gcurrency.rate_to_usd, 1))::real total_volume_in_usd
FROM gbalance
FULL JOIN guser ON gbalance.user_id = guser.id
FULL JOIN gcurrency ON gbalance.currency_id = gcurrency.id
ORDER BY name DESC, lastname, type ;
