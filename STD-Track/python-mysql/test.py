""" 
    Prerequisites 
        MySQL workbench

    Setup
        cmd -> python --version
        Python 3.12.2
        cmd -> python -m venv venv
        cmd -> .\venv\Scripts\activate
        cmd -> pip list
        cmd -> pip freeze > requirements.txt

"""

import mysql.connector

mydb = mysql.connector.connect(host="localhost", user="root", passwd="1qazZAQ!")

print(mydb)