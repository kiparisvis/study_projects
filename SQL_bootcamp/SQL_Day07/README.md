# Day 07 - Piscine SQL

## _Aggregated data is more informative, isn't it?_

## Contents

1. [Chapter I](#chapter-i) \
    1.1. [Exercise 00 - Simple aggregated information](#exercise-00-simple-aggregated-information)  
2. [Chapter II](#chapter-ii) \
    2.1. [Exercise 01 - Let’s see real names](#exercise-01-lets-see-real-names)  
3. [Chapter III](#chapter-iii) \
    3.1. [Exercise 02 - Restaurants statistics](#exercise-02-restaurants-statistics)  
4. [Chapter IV](#chapter-iv) \
    4.1. [Exercise 03 - Restaurants statistics #2](#exercise-03-restaurants-statistics-2)  
5. [Chapter V](#chapter-v) \
    5.1. [Exercise 04 - Clause for groups](#exercise-04-clause-for-groups)
6. [Chapter VI](#chapter-vi) \
    6.1. [Exercise 05 - Person's uniqueness](#exercise-05-persons-uniqueness)
7. [Chapter VII](#chapter-vii) \
    7.1. [Exercise 06 - Restaurant metrics](#exercise-06-restaurant-metrics)
8. [Chapter VIII](#chapter-viii) \
    8.1. [Exercise 07 - Average global rating](#exercise-07-average-global-rating)
9. [Chapter IX](#chapter-ix) \
    9.1. [Exercise 08 - Find pizzeria’s restaurant locations](#exercise-08-find-pizzerias-restaurant-locations)    
10. [Chapter X](#chapter-x) \
    10.1. [Exercise 09 - Explicit type transformation](#exercise-09-explicit-type-transformation)        

## Chapter I
## Exercise 00 - Simple aggregated information

| Exercise 00: Simple aggregated information |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 00                                                                                                                     |                                                                              |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL|

Let’s make a simple aggregation, please write a SQL statement that returns person identifiers and corresponding number of visits in any pizzerias and sorting by count of visits in descending mode and sorting in `person_id` in ascending mode. Please take a look at the sample of data below.

| person_id | count_of_visits |
| ------ | ------ |
| 9 | 4 |
| 4 | 3 |
| ... | ... | 


## Chapter II
## Exercise 01 - Let’s see real names

| Exercise 01: Let’s see real names|                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 01                                                                                                                     |                                                                               |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Please change a SQL statement from Exercise 00 and return a person name (not identifier). Additional clause is  we need to see only top-4 persons with maximal visits in any pizzerias and sorted by a person name. Please take a look at the example of output data below.

| name | count_of_visits |
| ------ | ------ |
| Dmitriy | 4 |
| Denis | 3 |
| ... | ... | 



## Chapter III
## Exercise 02 - Restaurants statistics

| Exercise 02: Restaurants statistics|                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 02                                                                                                                     |                                                                                |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Please write a SQL statement to see 3 favorite restaurants by visits and by orders in one list (please add an action_type column with values ‘order’ or ‘visit’, it depends on data from the corresponding table). Please take a look at the sample of data below. The result should be sorted by action_type column in ascending mode and by count column in descending mode.

| name | count | action_type |
| ------ | ------ | ------ |
| Dominos | 6 | order |
| ... | ... | ... |
| Dominos | 7 | visit |
| ... | ... | ... |

## Chapter IV
## Exercise 03 - Restaurants statistics #2

| Exercise 03: Restaurants statistics #2 |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 03                                                                                                                     |                                                                                |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Please write a SQL statement to see restaurants are grouping by visits and by orders and joined with each other by using restaurant name.  
You can use internal SQLs from Exercise 02 (restaurants by visits and by orders) without limitations of amount of rows.

Additionally, please add the next rules.
- calculate a sum of orders and visits for corresponding pizzeria (be aware, not all pizzeria keys are presented in both tables).
- sort results by `total_count` column in descending mode and by `name` in ascending mode.
Take a look at the data sample below.

| name | total_count |
| ------ | ------ |
| Dominos | 13 |
| DinoPizza | 9 |
| ... | ... | 


## Chapter V
## Exercise 04 - Clause for groups


| Exercise 04: Clause for groups |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 04                                                                                                                     |                                                                                |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |
| **Denied**                               |                                                                                                                          |
| Syntax construction                        | `WHERE`                                                                                              |

Please write a SQL statement that returns the person name and corresponding number of visits in any pizzerias if the person has visited more than 3 times (> 3).Please take a look at the sample of data below.

| name | count_of_visits |
| ------ | ------ |
| Dmitriy | 4 |



## Chapter VI
## Exercise 05 - Person's uniqueness


| Exercise 05: Person's uniqueness|                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 05                                                                                                                     |                                                                              |
| **Allowed**                               |                                                                                                                          |
| Language                        |  ANSI SQL                                                                                              |
| **Denied**                               |                                                                                                                          |
| Syntax construction                        |  `GROUP BY`, any type (`UNION`,...) working with sets                                                                                              |

Please write a simple SQL query that returns a list of unique person names who made orders in any pizzerias. The result should be sorted by person name. Please take a look at the sample below.

| name | 
| ------ |
| Andrey |
| Anna | 
| ... | 

## Chapter VII
## Exercise 06 - Restaurant metrics


| Exercise 06: Restaurant metrics|                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 06                                                                                                                     |                                                                                |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Please write a SQL statement that returns the amount of orders, average of price, maximum and minimum prices for sold pizza by corresponding pizzeria restaurant. The result should be sorted by pizzeria name. Please take a look at the data sample below. 
Round your average price to 2 floating numbers.

| name | count_of_orders | average_price | max_price | min_price |
| ------ | ------ | ------ | ------ | ------ |
| Best Pizza | 5 | 780 | 850 | 700 |
| DinoPizza | 5 | 880 | 1000 | 800 |
| ... | ... | ... | ... | ... |


## Chapter VIII
## Exercise 07 - Average global rating


| Exercise 07: Average global rating|                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 07                                                                                                                     |                                                                              |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Please write a SQL statement that returns a common average rating (the output attribute name is global_rating) for all restaurants. Round your average rating to 4 floating numbers.


## Chapter IX
## Exercise 08 - Find pizzeria’s restaurant locations


| Exercise 08: Find pizzeria’s restaurant locations|                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 08                                                                                                                     |                                                                               |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

We know about personal addresses from our data. Let’s imagine, that particular person visits pizzerias in his/her city only. Please write a SQL statement that returns address, pizzeria name and amount of persons’ orders. The result should be sorted by address and then by restaurant name. Please take a look at the sample of output data below.

| address | name |count_of_orders |
| ------ | ------ |------ |
| Kazan | Best Pizza |4 |
| Kazan | DinoPizza |4 |
| ... | ... | ... | 


## Chapter X
## Exercise 09 - Explicit type transformation


| Exercise 09: Explicit type transformation|                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 09                                                                                                                     |                                                                                |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Please write a SQL statement that returns aggregated information by person’s address , the result of “Maximal Age - (Minimal Age  / Maximal Age)” that is presented as a formula column, next one is average age per address and the result of comparison between formula and average columns (other words, if formula is greater than  average then True, otherwise False value).

The result should be sorted by address column. Please take a look at the sample of output data below.

| address | formula |average | comparison |
| ------ | ------ |------ |------ |
| Kazan | 44.71 |30.33 | true |
| Moscow | 20.24 | 18.5 | true |
| ... | ... | ... | ... |
