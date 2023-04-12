SELECT p.address, formula, average, formula > average
FROM (SELECT person.address, ROUND(MAX(person.age)::numeric - (MIN(person.age)::numeric / MAX(person.age)::numeric), 2)::real AS formula, ROUND(AVG(person.age), 2)::real AS average
FROM person
GROUP BY person.address) AS p
ORDER BY 1;
