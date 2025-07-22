/* 
SELECT (--- subquery ---)
FROM (--- subquery ---)
WHERE (--- subquery ---) -> Most comfortable
*/
USE dummydb;

SELECT * FROM employees;

-- MAIN PART
SELECT * FROM employees WHERE salary < 2500;

-- SUB PART
SELECT salary FROM employees WHERE employee_id = 100;

-- SUB QUERY (employees with less salary than employee with id 100)
SELECT * FROM employees WHERE salary < (SELECT salary FROM employees WHERE employee_id = 100);

-- SUB QUERY (employee with highest salary)
SELECT * FROM employees WHERE salary = (SELECT MAX(salary) FROM employees);

-- SUB QUERY (employee works in marketing department)

-- MAIN PART
SELECT * FROM employees WHERE department_id = 20;

-- SUB PART
SELECT department_id FROM departments WHERE department_name = 'Marketing';

SELECT * FROM employees WHERE department_id = (
    SELECT department_id FROM departments WHERE department_name = 'Marketing'
);

-- SUB QUERY (average of employee works in marketing department)
SELECT AVG(salary) AS 'Average Salary' FROM employees WHERE department_id = (
    SELECT department_id FROM departments WHERE department_name = 'Marketing'
);

-- SUB QUERY (total employee works in it department)
SELECT COUNT(*) AS 'Total Employees' FROM employees WHERE department_id = (
    SELECT department_id FROM departments WHERE department_name = 'It'
);

-- SUB QUERY (total employee works in IT & Marketing department)
SELECT department_id AS 'Department ID', COUNT(*) AS 'Total Employees' 
FROM employees 
GROUP BY department_id
HAVING department_id = (
    SELECT department_id FROM departments WHERE department_name = 'It'
) OR department_id = (
    SELECT department_id FROM departments WHERE department_name = 'Marketing'
);