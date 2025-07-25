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

-- SELECT
--     COUNT(department_id) AS number_of_employees,
--     department_id
-- FROM
--     employees
-- WHERE
--     department_id IS NOT NULL
-- GROUP BY
--     department_id;
--
--
-- QUESTION 6: 
-- ANS: 
--
--
-- QUESTION 7: 
-- ANS: 
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