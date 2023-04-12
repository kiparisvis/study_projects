# Day 04 - Piscine SQL

## _Snapshots, virtual tables… What is going on?_

## Contents
 
1. [Chapter I](#chapter-i) \
    1.1. [Exercise 00 - Let’s create separated views for persons](#exercise-00-lets-create-separated-views-for-persons)  
2. [Chapter II](#chapter-ii) \
    2.1. [Exercise 01 - From parts to common view](#exercise-01-from-parts-to-common-view)  
3. [Chapter III](#chapter-iii) \
    3.1. [Exercise 02 - “Store” generated dates in one place](#exercise-02-store-generated-dates-in-one-place)  
4. [Chapter IV](#chapter-iv) \
    4.1. [Exercise 03 - Find missing visit days with Database View](#exercise-03-find-missing-visit-days-with-database-view)  
5. [Chapter V](#chapter-v) \
    5.1. [Exercise 04 - Let’s find something from Set Theory](#exercise-04-lets-find-something-from-set-theory)
6. [Chapter VI](#chapter-vi) \
    6.1. [Exercise 05 - Let’s calculate a discount price for each person](#exercise-05-lets-calculate-a-discount-price-for-each-person)
7. [Chapter VII](#chapter-vii) \
    7.1. [Exercise 06 - Materialization from virtualization](#exercise-06-materialization-from-virtualization)
8. [Chapter VIII](#chapter-viii) \
    8.1. [Exercise 07 - Refresh our state](#exercise-07-refresh-our-state)
9. [Chapter IX](#chapter-ix) \
    9.1. [Exercise 08 - Just clear our database](#exercise-08-just-clear-our-database)

## Chapter I
## Exercise 00 - Let’s create separated views for persons

| Exercise 00: Let’s create separated views for persons |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 00                                                                                                                     |                                                                           |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Please create 2 Database Views (with similar attributes like the original table) based on simple filtering of gender of persons. Set the corresponding names for the database views: `v_persons_female` and `v_persons_male`.


## Chapter II
## Exercise 01 - From parts to common view

| Exercise 01: From parts to common view|                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 01                                                                                                                     |                                                                            |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Please use 2 Database Views from Exercise #00 and write SQL to get female and male person names in one list. Please set the order by person name. The sample of data is presented below.

| name |
| ------ |
| Andrey |
| Anna |
| ... |


## Chapter III
## Exercise 02 - “Store” generated dates in one place

| Exercise 02: “Store” generated dates in one place|                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 02                                                                                                                     |                                                                               |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |
| SQL Syntax Construction                        | `generate_series(...)`                                                                                              |

Please create a Database View (with name `v_generated_dates`) which should be “store” generated dates from 1st to 31th of January 2022 in DATE type. Don’t forget about order for the generated_date column.  

| generated_date |
| ------ |
| 2022-01-01 |
| 2022-01-02 |
| ... |


## Chapter IV
## Exercise 03 - Find missing visit days with Database View

| Exercise 03: Find missing visit days with Database View |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 03                                                                                                                     |                                                                               |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |


Please write a SQL statement which returns missing days for persons’ visits in January of 2022. Use `v_generated_dates` view for that task and sort the result by missing_date column. The sample of data is presented below.

| missing_date |
| ------ |
| 2022-01-11 |
| 2022-01-12 |
| ... |

## Chapter V
## Exercise 04 - Let’s find something from Set Theory


| Exercise 04: Let’s find something from Set Theory |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 04                                                                                                                     |                                                                               |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Please write a SQL statement which satisfies a formula `(R - S)∪(S - R)` .
Where R is the `person_visits` table with filter by 2nd of January 2022, S is also `person_visits` table but with a different filter by 6th of January 2022. Please make your calculations with sets under the `person_id` column and this column will be alone in a result. The result please sort by `person_id` column and your final SQL please present in `v_symmetric_union` (*) database view.

(*) to be honest, the definition “symmetric union” doesn’t exist in Set Theory. This is the author's interpretation, the main idea is based on the existing rule of symmetric difference. 



## Chapter VI
## Exercise 05 - Let’s calculate a discount price for each person


| Exercise 05: Let’s calculate a discount price for each person |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 05                                                                                                                     |                                                                               |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Please create a Database View `v_price_with_discount` that returns a person's orders with person names, pizza names, real price and calculated column `discount_price` (with applied 10% discount and satisfies formula `price - price*0.1`). The result please sort by person name and pizza name and make a round for `discount_price` column to integer type. Please take a look at a sample result below.


| name |  pizza_name | price | discount_price |
| ------ | ------ | ------ | ------ | 
| Andrey | cheese pizza | 800 | 720 | 
| Andrey | mushroom pizza | 1100 | 990 |
| ... | ... | ... | ... |




## Chapter VII
## Exercise 06 - Materialization from virtualization


| Exercise 06: Materialization from virtualization |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 06                                                                                                                     |                                                                                |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Please create a Materialized View `mv_dmitriy_visits_and_eats` (with data included) based on SQL statement that finds the name of pizzeria Dmitriy visited on January 8, 2022 and could eat pizzas for less than 800 rubles (this SQL you can find out at Day #02 Exercise #07). 

To check yourself you can write SQL to Materialized View `mv_dmitriy_visits_and_eats` and compare results with your previous query.


## Chapter VIII
## Exercise 07 - Refresh our state


| Exercise 07: Refresh our state|                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 07                                                                                                                     |                                                                              |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |
| **Denied**                               |                                                                                                                          |
| SQL Syntax Pattern                        | Don’t use direct numbers for identifiers of Primary Key, person and pizzeria                                                                                               |

Let's refresh data in our Materialized View `mv_dmitriy_visits_and_eats` from exercise #06. Before this action, please generate one more Dmitriy visit that satisfies the SQL clause of Materialized View except pizzeria that we can see in a result from exercise #06.
After adding a new visit please refresh a state of data for `mv_dmitriy_visits_and_eats`.

## Chapter IX
## Exercise 08 - Just clear our database


| Exercise 08: Just clear our database |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 08                                                                                                                     |                                                                              |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |           

After all our exercises were born a few Virtual Tables and one Materialized View. Let’s drop them!

