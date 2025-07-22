-- SELECT QUERY
USE mynewdatabase;

-- Writing Sequence 
-- ->  SELECT FROM WHERE ORDER BY LIMIT OFFSET

-- DISTINCT
--  SELECT DISTINCT DESIGNATION FROM EMPLOYEE

-- ORDER BY Ascending / Descending order
-- SELECT * FROM EMPLOYEE ORDER BY Age ASC/DESC

-- LIMIT/OFFSET
-- SELECT * FROM EMPLOYEE WHERE (Logic) LIMIT 10 OFFSET 50  -> (start from 51/don't include the first 50)
-- SELECT * FROM EMPLOYEE WHERE (Logic) LIMIT 50, 10 (Shorthand to top logic)

-- IN, NOT IN
-- SELECT * FROM EMPLOYEE WHERE ROLL = 101 OR ROLL = 102 OR ROLL = 104 
-- SELECT * FROM EMPLOYEE WHERE ROLL IN(101, 102, 104) -> output -> table with 101, 102, 104
-- SELECT * FROM EMPLOYEE WHERE ROLL NOT IN(101, 102, 104) -> output -> table without 101, 102, 104

-- LIKE
-- SELECT * FROM EMPLOYEE WHERE Name LIKE 'John%' -> output -> table with name contains John -> John Doe, John Smith
-- SELECT * FROM EMPLOYEE WHERE Name LIKE '%John%' -> output -> table with name contains John -> Mr. John Doe, Mrs. John Smith

-- AS -> Alias
-- SELECT Name As StudentName WHERE -> Output -> Name column will appear as StudentName

-- SELECT first_name AS "FIRST NAME" FROM employees WHERE last_name  LIKE "Green%" ORDER BY employee_id DESC LIMIT 1, 5;