-- Common Table Expressions (WITH AS) (The value is being saved as a table)
USE dummydb;

-- SELECT * FROM employees LIMIT 5;

WITH tmp AS (SELECT * FROM employees LIMIT 5)

SELECT * FROM tmp;

-- QUESTION 1 : Show the name of the employees who gets more salary than IT department's average salary but less that the salary of the maximum salary of Marketing department

WITH 
-- IT Average
avg_it AS (
    SELECT AVG(salary) AS avg_salary FROM employees WHERE department_id = 60
),
-- Marketing Max
max_marketing AS (
    SELECT MAX(salary) AS max_salary  FROM employees WHERE department_id = 20
)

SELECT * FROM employees WHERE salary > (SELECT avg_salary FROM avg_it) AND salary <  (SELECT max_salary FROM max_marketing);