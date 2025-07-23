USE dummydb;


-- INNER, LEFT, RIGHT, CROSS, SELF


SELECT * FROM employees;
SELECT * FROM departments;

-- Without Using Join Syntax | Not Efficient
SELECT CONCAT(employees.first_name, ' ', employees.last_name) AS 'full name', departments.department_name  
From employees, departments 
    WHERE employees.department_id = departments.department_id;

-- With Join Syntax | ON
SELECT CONCAT(employees.first_name, ' ', employees.last_name) AS 'full name', departments.department_name  
FROM employees 
    JOIN departments ON employees.department_id = departments.department_id;


-- With Join Syntax | USING | Needs to have exact column name
SELECT CONCAT(employees.first_name, ' ', employees.last_name) AS 'full name', departments.department_name  
FROM employees 
    JOIN departments USING(department_id);

-- Inner Join
SELECT CONCAT(employees.first_name, ' ', employees.last_name) AS 'full name', departments.department_name  
FROM employees 
    JOIN departments ON employees.department_id = departments.department_id;

SELECT CONCAT(employees.first_name, ' ', employees.last_name) AS 'full name', departments.department_name  
FROM employees 
    INNER JOIN departments ON employees.department_id = departments.department_id; -- JOIN -> INNER JOIN

-- Left Join
SELECT CONCAT(employees.first_name, ' ', employees.last_name) AS 'full name', departments.department_name  
FROM employees 
    LEFT JOIN departments ON employees.department_id = departments.department_id;

-- Right Join
SELECT CONCAT(employees.first_name, ' ', employees.last_name) AS 'full name', departments.department_name  
FROM employees 
    RIGHT JOIN departments ON employees.department_id = departments.department_id;

-- Cross Join
SELECT CONCAT(employees.first_name, ' ', employees.last_name) AS 'full name', departments.department_name  
FROM employees 
    CROSS JOIN departments ON employees.department_id = departments.department_id;

-- Self Join
SELECT * FROM employees AS e1
    JOIN employees AS e2 
    ON e1.department_id = e2.department_id;