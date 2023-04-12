# Day 00 - Piscine SQL

## _Relational Data Model and SQL_

## Contents

1. [Chapter I](#chapter-i) \
    1.1. [Exercise 00 - First steps into SQL world](#exercise-00-first-steps-into-sql-world)  
2. [Chapter II](#chapter-ii) \
    2.1. [Exercise 01 - First steps into SQL world](#exercise-01-first-steps-into-sql-world)  
3. [Chapter III](#chapter-iii) \
    3.1. [Exercise 02 - First steps into SQL world](#exercise-02-first-steps-into-sql-world)  
4. [Chapter IV](#chapter-iv) \
    4.1. [Exercise 03 - First steps into SQL world](#exercise-03-first-steps-into-sql-world)  
5. [Chapter V](#chapter-v) \
    5.1. [Exercise 04 - First steps into SQL world](#exercise-04-first-steps-into-sql-world)
6. [Chapter VI](#chapter-vi) \
    6.1. [Exercise 05 - First steps into SQL world](#exercise-05-first-steps-into-sql-world)
7. [Chapter VII](#chapter-vii) \
    7.1. [Exercise 06 - First steps into SQL world](#exercise-06-first-steps-into-sql-world)
8. [Chapter VIII](#chapter-viii) \
    8.1. [Exercise 07 - First steps into SQL world](#exercise-07-first-steps-into-sql-world)
9. [Chapter IX](#chapter-ix) \
    9.1. [Exercise 08 - First steps into SQL world](#exercise-08-first-steps-into-sql-world)
10. [Chapter X](#chapter-x) \
    10.1. [Exercise 09 - First steps into SQL world](#exercise-09-first-steps-into-sql-world)

## Chapter I
## Exercise 00 - First steps into SQL world

| Exercise 00: First steps into SQL world |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 00                                                                                                                     |                                                                                |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Let’s make our first task. 
Please make a select statement which returns all person's names and person's ages from the city ‘Kazan’.


## Chapter II
## Exercise 01 - First steps into SQL world

| Exercise 01: First steps into SQL world |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 01                                                                                                                     |                                                                             |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Please make a select statement which returns names , ages for all women from the city ‘Kazan’. Yep, and please sort result by name.

## Chapter III
## Exercise 02 - First steps into SQL world

| Exercise 02: First steps into SQL world |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 02                                                                                                                     |                                                                               |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Please make 2 syntax different select statements which return a list of pizzerias (pizzeria name and rating) with rating between 3.5 and 5 points (including limit points) and ordered by pizzeria rating.
- the 1st select statement must contain comparison signs  (<=, >=)
- the 2nd select statement must contain `BETWEEN` keyword

## Chapter IV
## Exercise 03 - First steps into SQL world

| Exercise 03: First steps into SQL world |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 03                                                                                                                     |                                                                                |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Please make a select statement which returns the person's identifiers (without duplication) who visited pizzerias in a period from 6th of January 2022 to 9th of January 2022 (including all days) or visited pizzeria with identifier 2. Also include ordering clause by person identifier in descending mode.

## Chapter V
## Exercise 04 - First steps into SQL world


| Exercise 04: First steps into SQL world |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 04                                                                                                                     |                                                                            |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Please make a select statement which returns one calculated field with name ‘person_information’ in one string like described in the next sample:

`Anna (age:16,gender:'female',address:'Moscow')`

Finally, please add the ordering clause by calculated column in ascending mode.
Please pay attention to quote symbols in your formula!

## Chapter VI
## Exercise 05 - First steps into SQL world


| Exercise 05: First steps into SQL world |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 05                                                                                                                     |                                                                                |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |
| **Denied**                               |                                           
| SQL Syntax Construction                        | `IN`, any types of `JOINs`                                                                                              |

Please make a select statement which returns person's names (based on internal query in `SELECT` clause) who made orders for the menu with identifiers 13 , 14 and 18 and date of orders should be equal 7th of January 2022. Be aware with "Denied Section" before your work.

Please take a look at the pattern of internal query.

    SELECT 
	    (SELECT ... ) AS NAME  -- this is an internal query in a main SELECT clause
    FROM ...
    WHERE ...

## Chapter VII
## Exercise 06 - First steps into SQL world


| Exercise 06: First steps into SQL world |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 06                                                                                                                     |                                                                                |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |
| **Denied**                               |                                           
| SQL Syntax Construction                        | `IN`, any types of `JOINs`                                                                                              |

Please use SQL construction from Exercise 05 and add a new calculated column (use column's name ‘check_name’) with a check statement (a pseudo code for this check is presented below) in the `SELECT` clause.

    if (person_name == 'Denis') then return true
        else return false

## Chapter VIII
## Exercise 07 - First steps into SQL world


| Exercise 07: First steps into SQL world |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 07                                                                                                                     |                                                                               |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Let’s apply data intervals for the `person` table. 
Please make a SQL statement which returns a person's identifiers, person's names and interval of person’s ages (set a name of a new calculated column as ‘interval_info’) based on pseudo code below. 

    if (age >= 10 and age <= 20) then return 'interval #1'
    else if (age > 20 and age < 24) then return 'interval #2'
    else return 'interval #3'

and yes...please sort a result by ‘interval_info’ column in ascending mode.

## Chapter IX
## Exercise 08 - First steps into SQL world


| Exercise 08: First steps into SQL world |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 08                                                                                                                     |                                                                              |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Please make a SQL statement which returns all columns from the `person_order` table with rows whose identifier is an even number. The result have to order by returned identifier.

## Chapter X
## Exercise 09 - First steps into SQL world


| Exercise 09: First steps into SQL world |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 09                                                                                                                     |                                                                                 |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |
| **Denied**                               |                                           
| SQL Syntax Construction                        | any types of `JOINs`                                                                                              |


Please make a select statement that returns person names and pizzeria names based on the `person_visit` table with date of visit in a period from 07th of January to 09th of January 2022 (including all days) (based on internal query in `FROM` clause) .


Please take a look at the pattern of the final query.

    SELECT (...) AS person_name ,  -- this is an internal query in a main SELECT clause
            (...) AS pizzeria_name  -- this is an internal query in a main SELECT clause
    FROM (SELECT … FROM person_visits WHERE …) AS pv -- this is an internal query in a main FROM clause
    ORDER BY ...

Please add a ordering clause by person name in ascending mode and by pizzeria name in descending mode
