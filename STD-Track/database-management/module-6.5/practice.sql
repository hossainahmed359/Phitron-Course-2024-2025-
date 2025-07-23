USE dummydb;

-- QUESTION 1 : Determine the third highest salary and which employee receives it?
SELECT * FROM employees WHERE salary = (
    SELECT DISTINCT(salary) FROM employees ORDER BY salary DESC LIMIT 2, 1
);

-- QUESTION 2 : Determine the third lowest salary and which employee receives it?
SELECT * FROM employees WHERE salary = (
    SELECT DISTINCT(salary) FROM employees ORDER BY salary ASC LIMIT 2, 1
);

-- QUESTION 3 : Which employee has been hired after Steven?
SELECT * FROM employees WHERE hire_date > (
    SELECT hire_date FROM employees WHERE first_name = 'Steven' AND employee_id = 100
);

-- QUESTION 4 : With common table expression solve the question 1 and 2
WITH 
third_highest_t AS (
    SELECT * FROM employees WHERE salary = (
        SELECT DISTINCT(salary) FROM employees ORDER BY salary DESC LIMIT 2, 1
    )
),
third_lowest_t AS (
    SELECT * FROM employees WHERE salary = (
        SELECT DISTINCT(salary) FROM employees ORDER BY salary ASC LIMIT 2, 1
    )
)

SELECT * FROM third_highest_t;

SELECT * FROM third_lowest_t;