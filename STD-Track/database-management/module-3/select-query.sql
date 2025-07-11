-- SELECT QUERY
USE mynewdatabase;

INSERT INTO Student
(Roll, Name, Email, Address, Age) VALUES (101, 'Alex', 'alexn@gmail.com', null, 18);

INSERT INTO Student
(Roll, Name, Email, Address, Age) VALUES (102, 'John', 'john@gmail.com', 'new street', 18);

SELECT Name, Roll, Email FROM Student WHERE Name = 'Alex';