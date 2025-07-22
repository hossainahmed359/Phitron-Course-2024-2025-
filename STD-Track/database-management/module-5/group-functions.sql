/* 
    MAX, MIN, AVG, SUM, COUNT
 */

USE dummydb;

SELECT * FROM employees;

SELECT MAX(salary) FROM employees;

SELECT AVG(salary) FROM employees;

SELECT COUNT(commission_pct) FROM employees /* NULL is not included */;

SELECT COUNT(*) FROM employees;  /* Meaning count row if any column in the row is not null / total row */

/* 
    GROUP BY, HAVING QUERY
    Group By is used to group rows that have the same values in specified columns into summary rows.
    It is often used with aggregate functions like COUNT, MAX, MIN, AVG, SUM.
    Having is a condition for GROUP BY
 */

USE dummydb;

SELECT * FROM employees;

SELECT department_id,  MAX(salary) FROM employees GROUP BY department_id;

SELECT department_id,  AVG(salary) FROM employees GROUP BY department_id;

SELECT department_id AS "Department ID",  COUNT(*) AS "Employee Count"  FROM employees GROUP BY department_id;

SELECT department_id AS "Department ID", AVG(salary) AS "Avg Salary"  
FROM employees 
WHERE department_id IS NOT NULL 
GROUP BY department_id
HAVING AVG(Salary) > 2000;


