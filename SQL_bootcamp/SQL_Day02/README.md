# Day 02 - Piscine SQL

## _Deep diving into JOINs in SQL_

## Contents
 
1. [Chapter I](#chapter-i) \
    1.1. [Exercise 00 - Move to the LEFT, move to the RIGHT](#exercise-00-move-to-the-left-move-to-the-right)  
2. [Chapter II](#chapter-ii) \
    2.1. [Exercise 01 - Find data gaps](#exercise-01-find-data-gaps)  
3. [Chapter III](#chapter-iii) \
    3.1. [Exercise 02 - FULL means ‘completely filled’](#exercise-02-full-means-completely-filled)  
4. [Chapter IV](#chapter-iv) \
    4.1. [Exercise 03 - Reformat to CTE](#exercise-03-reformat-to-cte)  
5. [Chapter V](#chapter-v) \
    5.1. [Exercise 04 - Find a favorite pizzas](#exercise-04-find-a-favorite-pizzas)
6. [Chapter VI](#chapter-vi) \
    6.1. [Exercise 05 - Investigate Person Data](#exercise-05-investigate-person-data)
7. [Chapter VII](#chapter-vii) \
    7.1. [Exercise 06 - Favorite pizzas for Denis and Anna](#exercise-06-favorite-pizzas-for-denis-and-anna)
8. [Chapter VIII](#chapter-viii) \
    8.1. [Exercise 07 - Cheapest pizzeria for Dmitriy](#exercise-07-cheapest-pizzeria-for-dmitriy)
9. [Chapter IX](#chapter-ix) \
    9.1. [Exercise 08 - Continuing to research data](#exercise-08-continuing-to-research-data)
10. [Chapter X](#chapter-x) \
    10.1. [Exercise 09 - Who loves cheese and pepperoni?](#exercise-09-who-loves-cheese-and-pepperoni)
11. [Chapter XI](#chapter-xi) \
    11.1. [Exercise 10 - Find persons from one city](#exercise-10-find-persons-from-one-city)

## Chapter I
## Exercise 00 - Move to the LEFT, move to the RIGHT

| Exercise 00: Move to the LEFT, move to the RIGHT |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 00                                                                                                                     |                                                                               |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |
| **Denied**                               |                                                                                                                          |
| SQL Syntax Construction                        | `NOT IN`, `IN`, `NOT EXISTS`, `EXISTS`, `UNION`, `EXCEPT`, `INTERSECT`                                                                                              |

Please write a SQL statement which returns a list of pizzerias names with corresponding rating value which have not been visited by persons. 


## Chapter II
## Exercise 01 - Find data gaps

| Exercise 01: Find data gaps|                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 01                                                                                                                     |                                                                                |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |
| SQL Syntax Construction                        | `generate_series(...)`                                                                                              |
| **Denied**                               |                                                                                                                          |
| SQL Syntax Construction                        | `NOT IN`, `IN`, `NOT EXISTS`, `EXISTS`, `UNION`, `EXCEPT`, `INTERSECT`                                                                                              |

Please write a SQL statement which returns the missing days from 1st to 10th of January 2022 (including all days) for visits  of persons with identifiers 1 or 2. Please order by visiting days in ascending mode. The sample of data with column name is presented below.

| missing_date |
| ------ |
| 2022-01-03 |
| 2022-01-04 |
| 2022-01-05 |
| ... |


## Chapter III
## Exercise 02 - FULL means ‘completely filled’

| Exercise 02: FULL means ‘completely filled’|                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 02                                                                                                                     |                                                                               |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |
| **Denied**                               |                                                                                                                          |
| SQL Syntax Construction                        | `NOT IN`, `IN`, `NOT EXISTS`, `EXISTS`, `UNION`, `EXCEPT`, `INTERSECT`                                                                                              |

Please write a SQL statement that returns a whole list of person names visited (or not visited) pizzerias during the period from 1st to 3rd of January 2022 from one side and the whole list of pizzeria names which have been visited (or not visited) from the other side. The data sample with needed column names is presented below. Please pay attention to the substitution value ‘-’ for `NULL` values in `person_name` and `pizzeria_name` columns. Please also add ordering for all 3 columns.

| person_name | visit_date | pizzeria_name |
| ------ | ------ | ------ |
| - | null | DinoPizza |
| - | null | DoDo Pizza |
| Andrey | 2022-01-01 | Dominos |
| Andrey | 2022-01-02 | Pizza Hut |
| Anna | 2022-01-01 | Pizza Hut |
| Denis | null | - |
| Dmitriy | null | - |
| ... | ... | ... |

## Chapter IV
## Exercise 03 - Reformat to CTE

| Exercise 03: Reformat to CTE |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 03                                                                                                                     |                                                                              |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |
| SQL Syntax Construction                        | `generate_series(...)`                                                                                              |
| **Denied**                               |                                                                                                                          |
| SQL Syntax Construction                        | `NOT IN`, `IN`, `NOT EXISTS`, `EXISTS`, `UNION`, `EXCEPT`, `INTERSECT`                                                                                              |

Let’s return back to Exercise #01, please rewrite your SQL by using the CTE (Common Table Expression) pattern. Please move into the CTE part of your "day generator". The result should be similar like in Exercise #01

| missing_date | 
| ------ | 
| 2022-01-03 | 
| 2022-01-04 | 
| 2022-01-05 | 
| ... |

## Chapter V
## Exercise 04 - Find a favorite pizzas


| Exercise 04: Find a favorite pizzas |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 04                                                                                                                     |                                                                             |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Find full information about all possible pizzeria names and prices to get mushroom or pepperoni pizzas. Please sort the result by pizza name and pizzeria name then. The result of sample data is below (please use the same column names in your SQL statement).

| pizza_name | pizzeria_name | price |
| ------ | ------ | ------ |
| mushroom pizza | Dominos | 1100 |
| mushroom pizza | Papa Johns | 950 |
| pepperoni pizza | Best Pizza | 800 |
| ... | ... | ... |

## Chapter VI
## Exercise 05 - Investigate Person Data


| Exercise 05: Investigate Person Data |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 05                                                                                                                     |                                                                              |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Find names of all female persons older than 25 and order the result by name. The sample of output is presented below.

| name | 
| ------ | 
| Elvira | 
| ... |



## Chapter VII
## Exercise 06 - Favorite pizzas for Denis and Anna


| Exercise 06: Favorite pizzas for Denis and Anna |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 06                                                                                                                     |                                                                              |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Please find all pizza names (and corresponding pizzeria names using `menu` table) that Denis or Anna ordered. Sort a result by both columns. The sample of output is presented below.

| pizza_name | pizzeria_name |
| ------ | ------ |
| cheese pizza | Best Pizza |
| cheese pizza | Pizza Hut |
| ... | ... |

## Chapter VIII
## Exercise 07 - Cheapest pizzeria for Dmitriy


| Exercise 07: Cheapest pizzeria for Dmitriy |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 07                                                                                                                     |                                                                               |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Please find the name of pizzeria Dmitriy visited on January 8, 2022 and could eat pizza for less than 800 rubles.

## Chapter IX
## Exercise 08 - Continuing to research data


| Exercise 08: Continuing to research data |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 08                                                                                                                     |                                                                              |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |           


Please find the names of all males from Moscow or Samara cities who orders either pepperoni or mushroom pizzas (or both) . Please order the result by person name in descending mode. The sample of output is presented below.

| name | 
| ------ | 
| Dmitriy | 
| ... |


## Chapter X
## Exercise 09 - Who loves cheese and pepperoni?


| Exercise 09: Who loves cheese and pepperoni? |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 09                                                                                                                     |                                                                                 |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Please find the names of all females who ordered both pepperoni and cheese pizzas (at any time and in any pizzerias). Make sure that the result is ordered by person name. The sample of data is presented below.

| name | 
| ------ | 
| Anna | 
| ... |


## Chapter XI
## Exercise 10 - Find persons from one city


| Exercise 10: Find persons from one city |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 10                                                                                                                     |                                                                                |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Please find the names of persons who live on the same address. Make sure that the result is ordered by 1st person, 2nd person's name and common address. The  data sample is presented below. Please make sure your column names are corresponding column names below.

| person_name1 | person_name2 | common_address | 
| ------ | ------ | ------ |
| Andrey | Anna | Moscow |
| Denis | Kate | Kazan |
| Elvira | Denis | Kazan |
| ... | ... | ... |
