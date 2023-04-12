# Team 01 - Piscine SQL

## _Data Warehouse_

## Contents
 
1. [Chapter I](#chapter-i) \
    1.1. [Exercise 00 - Classical DWH](#exercise-00-classical-dwh)  
2. [Chapter II](#chapter-ii) \
    2.1. [Exercise 01 - Detailed Query](#exercise-01-detailed-query)  

## Chapter I
## Exercise 00 - Classical DWH

| Exercise 00: Classical DWH|                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 00                                                                                                                     |                                                                          |
| **Allowed**                               |                                                                                                                          |
| Language                        |  SQL|

Let’s take a look at the data sources and first logical data layer (ODS - Operational Data Store) in the DWH.

![T01_01](misc/T01_01.png)

`User` table Definition (in a Green Source Database):

| Column Name | Description |
| ------ | ------ |
| ID | Primary Key |
| name | Name of User |
| lastname | Last name of User |

`Currency` table Definition (in a Red Source Database):

| Column Name | Description |
| ------ | ------ |
| ID | Primary Key |
| name | Currency Name |
| rate_to_usd | Ratio to USD currency |

`Balance` table Definition (in a Blue Source Database):

| Column Name | Description |
| ------ | ------ |
| user_id | “Virtual Foreign Key” to User table from other source |
| money | Amount of money |
| type | Type of balance (can be 0,1,...) |
| currency_id | “Virtual Foreign Key” to Currency table from other source |

Green, Red and Blue databases are independent data sources and satisfy the pattern of microservice. It means, there is a high risk of data anomalies (presented below).
- Tables are not in data consistency. It means there is a User, but does not have any rows in the Balance table, or vice versa, there is a Balance , but no rows in the User table. The same situation between Currency and Balance tables. (other words, doesn’t exist explicit Foreign Keys between them)
- Possible NULL values for name and lastname in User table
- All tables are working under OLTP (OnLine Transactional Processing) SQL traffic. It means there is an actual state of data at one time, historical changes are not saved for every table.

These 3 listed tables are data sources for the tables with the similar data models in the DWH area.

`User` table Definition (in a DWH Database):

| Column Name | Description |
| ------ | ------ |
| ID | Primary Key |
| name | Name of User |
| lastname | Last name of User |

`Currency` table Definition (in a DWH Database):

| Column Name | Description |
| ------ | ------ |
| ID | Mocked Primary Key |
| name | Currency Name |
| rate_to_usd | Ratio to USD currency |
| updated | Timestamp of event from source database |

`Mocked Primary Key`  means there are duplicates with the same ID, because a new updated attribute was added that transforms our Relational Model to Temporal Relational Model. 

Please take a look at the Data Sample for “EUR” currency below.
This sample is based on SQL statement

    SELECT *
    FROM Currency
    WHERE name = ‘EUR’
    ORDER BY updated DESC;

| ID | name | rate_to_usd | updated |
| ------ | ------ | ------ | ------ |
| 100 | EUR | 0.9 | 03.03.2022 13:31 |
| 100 | EUR | 0.89 | 02.03.2022 12:31 |
| 100 | EUR | 0.87 | 02.03.2022 08:00 |
| 100 | EUR | 0.9 | 01.03.2022 15:36 |
| ... | ... | ... | ... |

`Balance` table Definition (in a DWH Database):

| Column Name | Description |
| ------ | ------ |
| user_id | “Virtual Foreign Key” to User table from other source |
| money | Amount of money |
| type | Type of balance (can be 0,1,...) |
| currency_id | “Virtual Foreign Key” to Currency table from other source |
| updated | Timestamp of event from source database |

Please take a look at the Data Sample below.
This sample is based on SQL statement

    SELECT *
    FROM Balance
    WHERE user_id = 103
    ORDER BY type, updated DESC;

| user_id | money | type | currency_id | updated |
| ------ | ------ | ------ | ------ | ------ |
| 103 | 200 | 0 | 100 | 03.03.2022 12:31 |
| 103 | 150 | 0 | 100 | 02.03.2022 11:29 |
| 103 | 15 | 0 | 100 | 03.03.2022 08:00 |
| 103 | -100 | 1 | 102 | 01.03.2022 15:36 |
| 103 | 2000 | 1 | 102 | 12.12.2021 15:36 |
| ... | ... | ... | ... |... |

All tables in DWH inherit all anomalies from source tables as well.
- Tables are not in data consistency. 
- Possible NULL values for name and lastname in User table

Please write a SQL statement that returns the total volume (sum of all money) of transactions from user balance aggregated by user and balance type. Please be aware, all data should be processed including data with anomalies. Below presented a table of result columns and corresponding calculation formula.

| Output Column | Formula (pseudocode) |
| ------ | ------ |
| name | source: user.name if user.name is NULL then return `not defined` value |
| lastname | source: user.lastname if user.lastname is NULL then return `not defined` value |
| type | source: balance.type | 
| volume | source: balance.money need to summarize all money “movements” | 
| currency_name | source: currency.name if currency.name is NULL then return `not defined` value | 
| last_rate_to_usd | source: currency.rate_to_usd. take a last currency.rate_to_usd for corresponding currency if currency.rate_to_usd is NULL then return 1 | 
| total_volume_in_usd | source: volume , last_rate_to_usd. make a multiplication between volume and last_rate_to_usd |

Please take a look at a sample of output data below. Sort the result by user name in descending mode and then by user lastname and balance type in ascending mode.

| name | lastname | type | volume | currency_name | last_rate_to_usd | total_volume_in_usd |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| Петр | not defined | 2 | 203 | not defined | 1 | 203 |
| Иван | Иванов | 1 | 410 | EUR | 0.9 | 369 |
| ... | ... | ... | ... | ... | ... | ... |


## Chapter II
## Exercise 01 - Detailed Query

| Exercise 01: Detailed Query|                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | 01                                                                                                                     |                                                                           |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL|


Before deeper diving into this task please apply INSERTs statements below.

`insert into currency values (100, 'EUR', 0.85, '2022-01-01 13:29');`
`insert into currency values (100, 'EUR', 0.79, '2022-01-08 13:29');`

Please write a SQL statement that returns all Users , all Balance transactions (in this task please ignore currencies that do not have a key in the `Currency` table ) with currency name and calculated value of currency in USD for the nearest day.

Below presented a table of result columns and corresponding calculation formula.

| Output Column | Formula (pseudocode) |
| ------ | ------ |
| name | source: user.name if user.name is NULL then return `not defined` value |
| lastname | source: user.lastname if user.lastname is NULL then return `not defined` value |
| currency_name | source: currency.name | 
| currency_in_usd | involved sources: currency.rate_to_usd, currency.updated, balance.updated.Take a look at a graphical interpretation of the formula below.| 

![T01_02](misc/T01_02.png)

- need to find a nearest rate_to_usd of currency at the past (t1) 
- if t1 is empty (means no any rates at the past) then find a nearest rate_to_usd of currency at the future (t2)
- use t1 OR t2 rate to calculate a currency in USD format

Please take a look at a sample of output data below. Sort the result by user name in descending mode and then by user lastname and currency name in ascending mode.

| name | lastname | currency_name | currency_in_usd |
| ------ | ------ | ------ | ------ |
| Иван | Иванов | EUR | 150.1 |
| Иван | Иванов | EUR | 17 |
| ... | ... | ... | ... |
