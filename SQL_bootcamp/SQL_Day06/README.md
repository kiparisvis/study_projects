# Day 06 - Piscine SQL

## _Let's improve customer experience_

## Contents
 
1. [Chapter I](#chapter-i) \
    1.1. [Exercise 00 - Discounts, discounts , everyone loves discounts](#exercise-00-discounts-discounts-everyone-loves-discounts)  
2. [Chapter II](#chapter-ii) \
    2.1. [Exercise 01 - Let’s set personal discounts](#exercise-01-lets-set-personal-discounts)  
3. [Chapter III](#chapter-iii) \
    3.1. [Exercise 02 - Let’s recalculate a history of orders.](#exercise-02-lets-recalculate-a-history-of-orders)  
4. [Chapter IV](#chapter-iv) \
    4.1. [Exercise 03 - Improvements are in a way](#exercise-03-improvements-are-in-a-way)  
5. [Chapter V](#chapter-v) \
    5.1. [Exercise 04 - We need more Data Consistency](#exercise-04-we-need-more-data-consistency)
6. [Chapter VI](#chapter-vi) \
    6.1. [Exercise 05 - Data Governance Rules](#exercise-05-data-governance-rules)
7. [Chapter VII](#chapter-vii) \
    7.1. [Exercise 06 - Let’s automate Primary Key generation](#exercise-06-lets-automate-primary-key-generation)

## Chapter I
## Exercise 00 - Discounts, discounts , everyone loves discounts

| Exercise 00: Discounts, discounts , everyone loves discounts |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 00                                                                                                                     |                                                                             |
| **Allowed**                               |                                                                                                                          |
| Language                        | SQL, DML, DDL                                                                                              |

Let’s expand our data model to involve a new business feature.
Every person wants to see a personal discount and every business wants to be closer for clients.

Please think about personal discounts for people from one side and pizzeria restaurants from other. Need to create a new relational table (please set a name `person_discounts`) with the next rules.
- set id attribute like a Primary Key (please take a look on id column in existing tables and choose the same data type)
- set for attributes person_id and pizzeria_id foreign keys for corresponding tables (data types should be the same like for id columns in corresponding parent tables)
- please set explicit names for foreign keys constraints by pattern fk_{table_name}_{column_name},  for example `fk_person_discounts_person_id`
- add a discount attribute to store a value of discount in percent. Remember, discount value can be a number with floats (please just use `numeric` data type). So, please choose the corresponding data type to cover this possibility.



## Chapter II
## Exercise 01 - Let’s set personal discounts

| Exercise 01: Let’s set personal discounts|                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 01                                                                                                                     |                                                                                |
| **Allowed**                               |                                                                                                                          |
| Language                        | SQL, DML, DDL                                                                                              |

Actually, we created a structure to store our discounts and we are ready to go further and fill our `person_discounts` table with new records.

So, there is a table `person_order` that stores the history of a person's orders. Please write a DML statement (`INSERT INTO ... SELECT ...`) that makes  inserts new records into `person_discounts` table based on the next rules.
- take aggregated state by person_id and pizzeria_id columns 
- calculate personal discount value by the next pseudo code:

    `if “amount of orders” = 1 then
        “discount” = 10.5 
    else if “amount of orders” = 2 then 
        “discount” = 22
    else 
        “discount” = 30`

- to generate a primary key for the person_discounts table please use  SQL construction below (this construction is from the WINDOW FUNCTION  SQL area).
    
    `... ROW_NUMBER( ) OVER ( ) AS id ...`




## Chapter III
## Exercise 02 - Let’s recalculate a history of orders

| Exercise 02: Let’s recalculate a history of orders|                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 02                                                                                                                     |                                                                               |
| **Allowed**                               |                                                                                                                          |
| Language                        | SQL, DML, DDL                                                                                              |

Please write a SQL statement that returns orders with actual price and price with applied discount for each person in the corresponding pizzeria restaurant and sort by person name, and pizza name. Please take a look at the sample of data below.

| name | pizza_name | price | discount_price | pizzeria_name | 
| ------ | ------ | ------ | ------ | ------ |
| Andrey | cheese pizza | 800 | 624 | Dominos |
| Andrey | mushroom pizza | 1100 | 858 | Dominos |
| ... | ... | ... | ... | ... |

## Chapter IV
## Exercise 03 - Improvements are in a way

| Exercise 03: Improvements are in a way |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 03                                                                                                                     |                                                                             |
| **Allowed**                               |                                                                                                                          |
| Language                        | SQL, DML, DDL                                                                                              |


Actually, we have to make improvements to data consistency from one side and performance tuning from the other side. Please create a multicolumn unique index (with name `idx_person_discounts_unique`) that prevents duplicates of pair values person and pizzeria identifiers.

After creation of a new index, please provide any simple SQL statement that shows proof of index usage (by using `EXPLAIN ANALYZE`).
The example of “proof” is below
    
    ...
    Index Scan using idx_person_discounts_unique on person_discounts
    ...


## Chapter V
## Exercise 04 - We need more Data Consistency


| Exercise 04: We need more Data Consistency |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 04                                                                                                                     |                                                                                |
| **Allowed**                               |                                                                                                                          |
| Language                        | SQL, DML, DDL                                                                                              |

Please add the following constraint rules for existing columns of the `person_discounts` table.
- person_id column should not be NULL (use constraint name `ch_nn_person_id`)
- pizzeria_id column should not be NULL (use constraint name `ch_nn_pizzeria_id`)
- discount column should not be NULL (use constraint name `ch_nn_discount`)
- discount column should be 0 percent by default
- discount column should be in a range values from 0 to 100 (use constraint name `ch_range_discount`)


## Chapter VI
## Exercise 05 - Data Governance Rules


| Exercise 05: Data Governance Rules|                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 05                                                                                                                     |                                                                                |
| **Allowed**                               |                                                                                                                          |
| Language                        |  SQL, DML, DDL                                                                                              |

To satisfy Data Governance Policies need to add comments for the table and table's columns. Let’s apply this policy for the `person_discounts` table. Please add English or Russian comments (it's up to you) that explain what is a business goal of a table and all included attributes. 

## Chapter VII
## Exercise 06 - Let’s automate Primary Key generation


| Exercise 06: Let’s automate Primary Key generation|                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 06                                                                                                                     |                                                                             |
| **Allowed**                               |                                                                                                                          |
| Language                        | SQL, DML, DDL                                                                                              |
| **Denied**                               |                                                                                                                          |
| SQL Syntax Pattern                        | Don’t use hard-coded value for amount of rows to set a right value for sequence                                                                                              |

Let’s create a Database Sequence with the name `seq_person_discounts` (starting from 1 value) and set a default value for id attribute of `person_discounts` table to take a value from `seq_person_discounts` each time automatically. 
Please be aware that your next sequence number is 1, in this case please set an actual value for database sequence based on formula “amount of rows in person_discounts table” + 1. Otherwise you will get errors about Primary Key violation constraint.
