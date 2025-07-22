USE dummydb;

-- QUESTION 1: Find what is the second highest salary and who get's it

-- Method 1
SELECT DISTINCT salary, CONCAT(first_name , " " , last_name) AS 'Full Name', employee_id   FROM employees ORDER BY salary DESC LIMIT 1, 1;

-- Method 2
SELECT * FROM employees WHERE employee_id = (
    SELECT employee_id FROM employees ORDER BY salary DESC LIMIT 1, 1
);

-- Method 3
SELECT * FROM employees WHERE salary = (
    SELECT DISTINCT salary FROM employees ORDER BY salary DESC LIMIT 1, 1
);

-- Method 4
-- getting second hightest
SELECT MAX(salary) FROM employees WHERE salary < (SELECT MAX(salary) FROM employees);

-- adding to the subquery
SELECT * FROM employees WHERE salary = (
    SELECT MAX(salary) FROM employees WHERE salary < (SELECT MAX(salary) FROM employees)
);

-- QUESTION 2: Find the employees that get's more salary then their manager
SELECT * FROM employees AS emp WHERE salary > (
	SELECT salary FROM employees AS manager
    WHERE emp.manager_id = manager.employee_id
);

-- QUESTION 3: Find the employees that works in the same job as their manager
SELECT * FROM employees AS emp WHERE job_id = (
    SELECT job_id FROM employees AS manager WHERE emp.manager_id = manager.employee_id
);