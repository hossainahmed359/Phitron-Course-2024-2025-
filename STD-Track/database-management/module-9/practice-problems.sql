-- https://leetcode.com/problems/duplicate-emails/
-- Problem: Write a solution to report all the duplicate emails.
-- Solution:
SELECT
    email
FROM
    Person
GROUP BY
    (email)
HAVING
    COUNT(email) > 1;

-- https://leetcode.com/problems/employees-earning-more-than-their-managers/description/
-- Problem: Write a solution to find the employees who earn more than their managers.
-- Solution:
SELECT
    name AS 'Employee'
FROM
    Employee AS e
WHERE
    salary > (
        SELECT
            salary
        FROM
            Employee AS m
        WHERE
            e.managerId = m.id
    );

-- https://leetcode.com/problems/customers-who-never-order/submissions/1713628958/
-- Problem: Write a solution to find all customers who never order anything.
-- Solution: 1
WITH
    tmp AS (
        SELECT
            c.id,
            c.name,
            o.id AS 'order_id'
        FROM
            Customers AS c
            LEFT JOIN Orders AS o ON c.id = o.customerId
    )
SELECT
    name AS Customers
FROM
    tmp
WHERE
    order_id IS NULL;

-- Solution: 2
SELECT
    name AS Customers
FROM
    Customers
    LEFT JOIN ORDERS ON Customers.id = Orders.customerId
GROUP BY
    Customers.id
HAVING
    COUNT(Orders.id) = 0;

-- Solution: 3
SELECT
    name AS Customers
FROM
    Customers
WHERE
    id NOT IN (
        SELECT
            customerId
        FROM
            Orders
    );

