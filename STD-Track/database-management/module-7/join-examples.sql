USE dummydb;

SELECT * FROM employees;
SELECT * FROM departments;

-- QUESTION 1 : Write a query to show the employees first name and their manager's name
SELECT 
e.employee_id AS 'Employee ID', CONCAT(e.first_name, ' ', e.last_name) AS 'Employee Full name', m.employee_id AS 'Manager ID', CONCAT(m.first_name, ' ', m.last_name) AS 'Manager Full name'
FROM employees AS e 
    INNER JOIN employees AS m 
        ON e.manager_id = m.employee_id;

SELECT 
e.employee_id AS 'Employee ID', CONCAT(e.first_name, ' ', e.last_name) AS 'Employee Full name', m.employee_id AS 'Manager ID', CONCAT(m.first_name, ' ', m.last_name) AS 'Manager Full name'
FROM employees AS e 
    LEFT JOIN employees AS m 
        ON e.manager_id = m.employee_id;

-- QUESTION 2 : Write a query to show the departments where there is not employee in that department
SELECT
d.department_id, d.department_name, e.employee_id
FROM departments AS d
    LEFT JOIN employees AS e
        ON d.department_id = e.department_id
WHERE e.employee_id IS NULL;

-- QUESTION 3 : Write a query to show the first name, salary, the value of how much less salary he/she gets from the average salary in his department
--1
SELECT e.employee_id, e.first_name, e.salary, (SELECT AVG(salary) FROM employees WHERE department_id = e.department_id) - e.salary AS 'less avg salary'
FROM employees AS e
    JOIN departments AS d
        ON e.department_id = d.department_id;

-- 2
WITH t_avg AS (
	SELECT AVG(salary) AS avg_salary, department_id
    FROM employees
    GROUP BY department_id
)

SELECT e1.employee_id, e1.first_name, e1.salary, e2.avg_salary, e2.avg_salary - e1.salary AS 'less from avg salary', d.department_name
FROM employees AS e1
    LEFT JOIN 
        t_avg AS e2
		ON e1.department_id = e2.department_id
			LEFT JOIN 
            departments AS d
			ON e1.department_id = d.department_id;



-- QUESTION 4 :