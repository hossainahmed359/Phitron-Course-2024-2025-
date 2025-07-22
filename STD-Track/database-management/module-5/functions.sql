-- https://www.w3schools.com/sql/sql_ref_mysql.asp

USE dummydb;

SELECT UPPER(first_name) FROM employees;
SELECT LOWER(first_name) FROM employees;
SELECT CONCAT(first_name, ' ', last_name) AS full_name FROM employees;

SELECT RAND()* 100 AS random_number FROM employees;
SELECT ROUND(123.4567, 2) AS rounded_value FROM employees;