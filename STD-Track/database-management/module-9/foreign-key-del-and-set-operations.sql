DROP SCHEMA IF EXISTS tempdb;

CREATE SCHEMA tempdb COLLATE = utf8_general_ci;

USE tempdb;

-- Foreign key delete operation
CREATE TABLE
    Student (
        Roll VARCHAR(5) PRIMARY KEY,
        Name VARCHAR(50),
        Phone VARCHAR(11)
    );

CREATE TABLE
    CourseName (
        CourseName VARCHAR(50) PRIMARY KEY,
        Roll VARCHAR(5),
        -- FOREIGN KEY (Roll) REFERENCES Student (Roll) 
        FOREIGN KEY (Roll) REFERENCES Student (Roll) ON DELETE CASCADE /* CASCADE, SET NULL */
    );

-- Set operations (UNION, UNION ALL, INTERSECTION, MINUS)
/* 
A = {1, 2, 3, 4}
B = {2, 4, 5, 6}

UNION = { 1, 2, 3, 4, 5, 6}
UNION ALL = {1, 2, 3, 4, 2, 4, 5, 6}
INTERSECTION = {2, 4}
MINUS = {1, 3, 5, 6}

 */
USE dummydb;

-- UNION 
SELECT
    first_name
FROM
    employees
WHERE
    salary > 10000
UNION
SELECT
    first_name
FROM
    employees
WHERE
    department_id = 100;

-- UNION ALL
SELECT
    first_name
FROM
    employees
WHERE
    salary > 10000
UNION ALL
SELECT
    first_name
FROM
    employees
WHERE
    department_id = 100;

-- INTERSECT
SELECT
    first_name
FROM
    employees
WHERE
    salary > 10000
INTERSECT
SELECT
    first_name
FROM
    employees
WHERE
    department_id = 100;

-- MINUS
SELECT
    first_name
FROM
    employees
WHERE
    salary > 10000
MINUS /* No Longer Supported */
SELECT
    first_name
FROM
    employees
WHERE
    department_id = 100;