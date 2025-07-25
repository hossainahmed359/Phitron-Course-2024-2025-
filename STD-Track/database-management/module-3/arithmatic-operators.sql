-- ARITHMETIC OPERATORS
USE mynewdatabase;

CREATE TABLE Marks(
	Roll CHAR(5),
    CSE INT,
    EEE INT,
    CONSTRAINT pk_rule PRIMARY KEY(Roll),
    CONSTRAINT cse_not_null_rule CHECK(CSE BETWEEN -1 AND 101),
    CONSTRAINT eee_not_null_rule CHECK(EEE BETWEEN -1 AND 101)
);

INSERT INTO Marks
(Roll, CSE, EEE) VALUES (101, 50, 60);
INSERT INTO Marks
(Roll, CSE, EEE) VALUES (102, 30, 22);
INSERT INTO Marks
(Roll, CSE, EEE) VALUES (103, 64, 90);
INSERT INTO Marks
(Roll, CSE, EEE) VALUES (104, 100, 76);
INSERT INTO Marks
(Roll, CSE, EEE) VALUES (105, 60, 50);


SELECT CSE + EEE FROM Marks WHERE CSE > 30 AND EEE <= 90;
