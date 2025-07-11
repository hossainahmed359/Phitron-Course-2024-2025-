-- CONSTRAINTS

USE mynewdatabase;

-- First Method
CREATE TABLE Student(
	Roll CHAR(5) PRIMARY KEY UNIQUE,
    Name VARCHAR(50) NOT NULL,
    Email VARCHAR(50) UNIQUE,
    Address VARCHAR(255),
    Age INT CHECK(Age>10)
);

-- Second Method
CREATE TABLE StudentTwo(
	Roll CHAR(5),
    Name VARCHAR(50) NOT NULL,
    Email VARCHAR(50),
    Address VARCHAR(255),
    Age INT,
	PRIMARY KEY(Roll),
    UNIQUE(Email),
    CHECK(Age > 10)
    
);

-- Third Method
CREATE TABLE StudentThree(
	Roll CHAR(5),
    Name VARCHAR(50),
    Email VARCHAR(50),
    Address VARCHAR(255),
    Age INT,
	Constraint pk_rule PRIMARY KEY(Roll),
    Constraint unique_email_rule UNIQUE(Email),
    Constraint checking_age_rul CHECK(Age > 10)
);


CREATE TABLE Library(
	BookName VARCHAR(50) PRIMARY KEY,
    WhoHired_Roll CHAR(5),
    Constraint Foreign KEY (WhoHired_Roll) REFERENCES Student(Roll)
);

CREATE TABLE Course(
	CourseName VARCHAR(10),
    University  VARCHAR(10),
    Credit INT,
    Constraint PRIMARY KEY(CourseName, University),
    Constraint check_credit CHECK(Credit > 0)
);

INSERT INTO Student
(Roll, Name, Email, Address, Age) VALUES (4531, 'John Doe', 'john@gmail.com', null, 11);