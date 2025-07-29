import mysql.connector

db_name = "dummydb"

mydbconnection = mysql.connector.connect(
    host="localhost",
    user="root",
    passwd="1qazZAQ!",
    database=db_name
)

mycursor = mydbconnection.cursor()

sqlquery = """
            SELECT
                *
            FROM
                employees;
            """
mycursor.execute(sqlquery)
# mydbconnection.commit()

# Fetch all results
results = mycursor.fetchall()

# Print each row
print("Employees with salary > 10,000:")
for row in results:
    print(row)  # Prints first_name (since we selected only one column)

# Close cursor & connection (good practice)
mycursor.close()
mydbconnection.close()