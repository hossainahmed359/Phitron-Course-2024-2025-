-- CONSTRAINT
USE mynewdatabase;

-- Student
CREATE TABLE Student(
	Roll CHAR(5),
    Name VARCHAR(50),
    Email VARCHAR(50),
    Address VARCHAR(250),
    Age INT,
    CONSTRAINT pk_rule PRIMARY KEY(ROLL),
    CONSTRAINT name_not_null CHECK(Name is not null),
    CONSTRAINT unique_email_rule UNIQUE(Email),
    CONSTRAINT age_check_rule CHECK(Age > 5)
);

-- Library
CREATE TABLE Library(
	BookName VARCHAR(50),
    WhoHired_Roll CHAR(5),
    CONSTRAINT pk_rule PRIMARY KEY(BookName),
    CONSTRAINT fk_rule FOREIGN KEY(WhoHired_Roll) REFERENCES Student(Roll)
);

-- Course  
CREATE TABLE Course(
	CourseName VARCHAR(10),
    University VARCHAR(10),
    Credit INT,
    CONSTRAINT pk_rule PRIMARY KEY(CourseName, University),
    CONSTRAINT check_credit_rule CHECK(Credit > 0)
);

INSERT INTO Student
(Roll, Name, Email, Address, Age) VALUES (4531, 'John Doe', 'john@gmail.com', null, 11);

INSERT INTO Student
(Roll, Name, Email, Address, Age) VALUES (4532, 'John Smith', 'johnsmith@gmail.com', null, 22);


SELECT * FROM mynewdatabase.Student;