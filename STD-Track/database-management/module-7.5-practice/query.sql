USE dummydb;

-- SELECT * FROM employees;
-- SELECT * FROM departments;
-- SELECT * FROM jobs;

-- QUESTION 1: Show the employee names and corresponding job_titles without using JOIN query
SELECT
    CONCAT (employees.first_name, ' ', employees.last_name) AS 'Employee Name',
    jobs.job_title AS 'Job Title'
FROM
    employees,
    jobs
WHERE
    employees.job_id = jobs.job_id;

-- QUESTION 2: Do the question no 1 using JOIN query
SELECT
    CONCAT (e.first_name, ' ', e.last_name) AS 'Employee Name',
    j.job_title AS 'Job Title'
FROM
    employees AS e
    LEFT JOIN jobs AS j ON e.job_id = j.job_id;

-- QUESTION 3: Show the name of the employee and the job_title who receives the maximum salary
SELECT
    CONCAT (e.first_name, ' ', e.last_name) AS 'Employee Name',
    e.salary,
    j.job_title AS 'Job Title'
FROM
    employees AS e
    LEFT JOIN jobs AS j ON e.job_id = j.job_id
WHERE
    e.salary = (
        SELECT
            MAX(salary)
        FROM
            employees
    );

-- QUESTION 4: Show the list of employee name and corresponding manager names.
SELECT
    e.employee_id,
    CONCAT (e.first_name, ' ', e.last_name) AS 'Employee Name',
    m.employee_id AS 'manager_employee_id',
    CONCAT (m.first_name, ' ', m.last_name) AS 'Manager Name'
FROM
    employees AS e
    LEFT JOIN employees AS m ON e.manager_id = m.employee_id;