-- CREATE database MyNewDatabase;
USE MyNewDatabase;

CREATE TABLE Student(
	Roll CHAR(4) PRIMARY KEY,
    Name VARCHAR(50),
    Marks DOUBLE
);

INSERT INTO Student
(Roll, Name, Marks) VALUES(1, 'John', 90);

INSERT INTO Student
(Roll, Name, Marks) VALUES(2, 'Smith', 92);

SET SQL_SAFE_UPDATES = 0;

UPDATE Student
SET Name = 'John Doe' 
WHERE Roll = 1;

SET SQL_SAFE_UPDATES = 1;

SET SQL_SAFE_UPDATES = 0; -- off
-- SET SQL_SAFE_UPDATES = 1; -- on

DROP TABLE Student;

SELECT * FROM MyNewDatabase.Student;