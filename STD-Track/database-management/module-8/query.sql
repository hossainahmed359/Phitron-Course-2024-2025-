USE dummydb;

-- SELECT * FROM employees;
-- SELECT * FROM departments;
-- SELECT * FROM jobs;
--
--
-- QUESTION 1: Explain the difference between Primary Key and Foreign Key in SQL.
-- ANS: 
-- Primary key is a unique value of a record in a table. It is used to prevent duplication. A primary key must be unique. 
-- Foreign key is a stored primary key of another table. It is used to establish relation between multiple tables
--
--
-- QUESTION 2: What is a Self Join? Provide an example using the employees table to list employees who share the same manager ID, showing only their first names and manager IDs.
-- ANS: 
-- Self Join is a join operation where a table is joined with itself and returns joined table based on the ON clause.
USE dummydb;

SELECT
    e1.first_name,
    e1.manager_id
FROM
    employees AS e1
    JOIN (
        SELECT DISTINCT
            (manager_id) AS manager_id
        FROM
            employees
        WHERE
            manager_id IS NOT NULL
    ) AS e2 ON e1.manager_id = e2.manager_id;

--
--
-- QUESTION 3: PENDING
-- ANS: 
--
--
-- QUESTION 4: Using the dummydb, write an SQL query to get the third-highest salary in the employees table.
-- ANS: 
USE dummydb;

SELECT
    salary
FROM
    employees
ORDER BY
    salary DESC
LIMIT
    2, 1;

--
--
-- QUESTION 5: Write a query to show the department names and the number of employees in each department.
-- ANS:
USE dummydb;

SELECT
    d.department_name,
    e.number_of_employees
FROM
    (
        SELECT
            COUNT(department_id) AS number_of_employees,
            department_id
        FROM
            employees
        WHERE
            department_id IS NOT NULL
        GROUP BY
            department_id
    ) AS e
    RIGHT JOIN departments AS d ON e.department_id = d.department_id;

--
--
-- QUESTION 6: Illustrate INNER JOIN, LEFT JOIN, RIGHT JOIN, and CROSS JOIN with examples using the employees and departments tables.
-- ANS: 
USE dummydb;

-- INNER JOIN
SELECT
    e.employee_id,
    e.first_name,
    d.department_name
FROM
    employees AS e
    JOIN departments AS d ON e.department_id = d.department_id;

-- LEFT JOIN
SELECT
    e.employee_id,
    e.first_name,
    d.department_name
FROM
    employees AS e
    JOIN departments AS d ON e.department_id = d.department_id;

-- RIGHT JOIN
SELECT
    d.department_name,
    e.number_of_employees
FROM
    (
        SELECT
            COUNT(department_id) AS number_of_employees,
            department_id
        FROM
            employees
        WHERE
            department_id IS NOT NULL
        GROUP BY
            department_id
    ) AS e
    RIGHT JOIN departments AS d ON e.department_id = d.department_id;

-- CROSS JOIN
SELECT
    e.employee_id,
    e.first_name,
    d.department_name
FROM
    employees AS e
    CROSS JOIN departments AS d;

--
--
-- QUESTION 7: What is a Common Table Expression (CTE)? Write an example query using CTE to show the names of employees whose salary is higher than the average salary
-- ANS: 
-- CTE OR Common Table Expression a temporary named result set that is defined with in the execution scope
USE dummydb;

WITH
    avg_t AS (
        SELECT
            AVG(salary) as avg_salary
        FROM
            employees
    )
SELECT
    CONCAT (first_name, ' ', last_name) AS 'Full Name',
    salary
FROM
    employees
WHERE
    salary > (
        SELECT
            avg_salary
        FROM
            avg_t
    );

--
--
-- QUESTION 8: 
-- ANS: 
--
--
-- QUESTION 9:
-- ANS: 
--
--
-- QUESTION 10:
-- ANS: 
--
--