/* 
    ALTER , DROP , RENAME , ADD , MODIFY , CHANGE
    these are the commands used to alter a table structure in SQL.
 */

ALTER TABLE employees ADD COLUMN birth_date DATE;

ALTER TABLE employees DROP COLUMN birth_date;

ALTER TABLE employees ADD COLUMN temp_address VARCHAR(20);

ALTER TABLE employees MODIFY COLUMN temp_address VARCHAR(50);

SELECT * FROM employees;
