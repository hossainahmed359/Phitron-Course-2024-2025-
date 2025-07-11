USE MyNewDatabase;

CREATE TABLE employee (
	EmployeeId CHAR(5) PRIMARY KEY,
    EmployeeName VARCHAR(50),
    EmployeeSalary NUMERIC,
    JoiningDate DATETIME
);

INSERT INTO employee
(EmployeeId, EmployeeName, EmployeeSalary, JoiningDate) VALUES (4531, 'John', 1000, '2007-09-09');

INSERT INTO employee
(EmployeeId, EmployeeName, EmployeeSalary, JoiningDate) VALUES (4532, 'Doe', 5000, '2007-11-11');

-- INSERT INTO employee
-- (EmployeeId, EmployeeName, EmployeeSalary, JoiningDate) VALUES (4533, 'Smith', 1200, '2006-11-11');

-- SELECT * FROM MyNewDatabase.employee;

-- SET SQL_SAFE_UPDATES = 0;
-- DELETE FROM employee WHERE EmployeeId = 4532;

-- SELECT * FROM MyNewDatabase.employee;

-- DROP TABLE employee;