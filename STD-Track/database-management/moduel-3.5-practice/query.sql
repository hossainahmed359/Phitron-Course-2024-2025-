USE MyNewDatabase;

CREATE TABLE Employee 
(
	EmpId CHAR(6),
	EmpName VARCHAR(50),
	JoiningYear DATE,
	Birthday DATE,
	Designation VARCHAR(50),
	Salary INT,
	CONSTRAINT employee_pk_rule PRIMARY KEY(EmpId, EmpName),
    CONSTRAINT employee_birth_year_rule CHECK(YEAR(Birthday) <= 2000)
);

INSERT INTO Employee
(EmpId, EmpName, JoiningYear, Birthday, Designation, Salary) VALUES ('ECX267', 'John Doe', '2024-12-01', '2000-09-18', 'S.E', 50000);

INSERT INTO Employee
(EmpId, EmpName, JoiningYear, Birthday, Designation, Salary) VALUES ('ECX268', 'John Smith', '2020-12-01', '1998-05-01', 'S.S.E', 100000);

INSERT INTO Employee
(EmpId, EmpName, JoiningYear, Birthday, Designation, Salary) VALUES ('ECX269', 'Tom Riddle', '2020-12-01', '2000-05-01', 'J.S.E', 25000);

INSERT INTO Employee
(EmpId, EmpName, JoiningYear, Birthday, Designation, Salary) VALUES ('ECX270', 'Jessica', '2024-12-01', '2000-09-18', 'Q.A', 45000);

INSERT INTO Employee
(EmpId, EmpName, JoiningYear, Birthday, Designation, Salary) VALUES ('ECX271', 'Mike', '2020-12-01', '1998-05-01', 'P.M', 35000);

INSERT INTO Employee
(EmpId, EmpName, JoiningYear, Birthday, Designation, Salary) VALUES ('ECX272', 'Tim Andrew', '2020-12-01', '1996-05-01', 'Designer', 70000);

INSERT INTO Employee
(EmpId, EmpName, JoiningYear, Birthday, Designation, Salary) VALUES ('ECX273', 'Alex', '2024-12-01', '1999-09-18', 'L.S.E', 10000);

INSERT INTO Employee
(EmpId, EmpName, JoiningYear, Birthday, Designation, Salary) VALUES ('ECX274', 'Faiyyaz', '2020-12-01', '1995-05-01', 'S.E', 50000);

INSERT INTO Employee
(EmpId, EmpName, JoiningYear, Birthday, Designation, Salary) VALUES ('ECX275', 'Smith', '2020-12-01', '1992-05-01', 'S.E', 50000);

INSERT INTO Employee
(EmpId, EmpName, JoiningYear, Birthday, Designation, Salary) VALUES ('ECX276', 'Micheal', '2024-12-01', '1990-09-18', 'Q.A', 50000);

INSERT INTO Employee
(EmpId, EmpName, JoiningYear, Birthday, Designation, Salary) VALUES ('ECX277', 'Sia', '2020-12-01', '2000-05-01', 'Designer', 50000);

INSERT INTO Employee
(EmpId, EmpName, JoiningYear, Birthday, Designation, Salary) VALUES ('ECX278', 'May End', '2020-12-01', '2000-05-01', 'Designer', 50000);


SELECT * FROM Employee LIMIT 5, 10;
SELECT * FROM Employee ORDER BY YEAR(Birthday) ASC LIMIT 5, 10;