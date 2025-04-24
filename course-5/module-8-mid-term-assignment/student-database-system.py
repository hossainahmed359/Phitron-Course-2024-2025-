class StudentDatabase:
    __instance = None
    __student_list = []

    def __init__(self):
        if StudentDatabase.__instance is not None:
            raise Exception("StudentDatabase already has an instance")
        else:
            StudentDatabase.__instance = self

    @staticmethod
    def get_instance():
        if StudentDatabase.__instance is None:
            StudentDatabase()
        return StudentDatabase.__instance

    @classmethod
    def add_student(cls, student):
        cls.__student_list.append(student)

    @classmethod
    def get_all_students(cls):
        return cls.__student_list.copy()

    @classmethod
    def clear_database(cls):
        cls.__student_list.clear()

class Student:
    def __init__(self, student_id, name, department, is_enrolled):
        self.__student_id = student_id
        self.__name = name
        self.__department = department
        self.__is_enrolled = is_enrolled

    @property
    def student_id(self):
        return self.__student_id

    @property
    def is_enrolled(self):
        return self.__is_enrolled

    def enroll_student(self):
        if self.__is_enrolled is False:
            self.__is_enrolled = True

    def drop_student(self):
            self.__is_enrolled = False

    def view_student_info(self):
        print({'student_id': self.__student_id, 'name': self.__name, 'department': self.__department, 'is_enrolled': self.__is_enrolled})
        
def get_student_db () :
    student_data_arr = [
            {"student_id": "S001", "name": "Alice", "department": "CS", "is_enrolled": True},
            {"student_id": "S002", "name": "Bob", "department": "EE", "is_enrolled": True},
            {"student_id": "S003", "name": "Charlie", "department": "ME", "is_enrolled": False},
            {"student_id": "S004", "name": "Diana", "department": "CS", "is_enrolled": True},
            {"student_id": "S005", "name": "Eve", "department": "EE", "is_enrolled": False},
            {"student_id": "S006", "name": "Frank", "department": "ME", "is_enrolled": True},
            {"student_id": "S007", "name": "Grace", "department": "CS", "is_enrolled": True},
    ]

    NEW_STUDENT_DB = StudentDatabase.get_instance()

    for data in student_data_arr:
        new_student = Student(**data) 
        NEW_STUDENT_DB.add_student(new_student)

    return NEW_STUDENT_DB

def init(): 
    print('STUDENT DATABASE MANAGEMENT\n')

    STUDENT_DB = get_student_db()

    def view_all_students ():
        print("\nStudent List:")
        for Student in STUDENT_DB.get_all_students():
            Student.view_student_info()

    def enroll_student ():
        entered_student_id = input("Enter valid student ID to enroll: ").strip()

        student_found = False

        for Student in STUDENT_DB.get_all_students() :
            if(Student.student_id == entered_student_id):
                if(Student.is_enrolled == True):
                    raise Exception("Trying to enroll a student who is already enrolled.")
                else:
                    Student.enroll_student()
                    print("Enrollment Successful!")

                student_found = True
                break

        if student_found is False:
            raise Exception("Invalid student ID when enrolling a student.")


    def drop_student ():
        entered_student_id = input("Enter valid student ID to drop: ").strip()

        student_found = False

        for Student in STUDENT_DB.get_all_students() :
            if(Student.student_id == entered_student_id):

                if(Student.is_enrolled == True):
                    Student.drop_student()
                    print("Drop Successful!")
                else:
                    raise Exception("Trying to drop a student who is not enrolled.")

                student_found = True
                break

        if student_found is False:
            raise Exception("Invalid student ID when dropping a student.")

    def display_menu_options(): 
        
        print('Command Options:')
        print('1 : View All Students')
        print('2 : Enroll Student')
        print('3 : Drop Student')
        print('4 : Exit')

    def menu_system() :
        while True:
            try:

                value = int(input("\nEnter command (1-4): "))
            
                if(value == 1) :
                    view_all_students()
                elif(value == 2) :
                    enroll_student()
                elif(value == 3) :
                    drop_student()
                elif(value == 4) :
                    print("Exiting Menu.\nThanks!")
                    break
                else:
                    raise Exception("Invalid Command")

            except ValueError :
                print("Error: Invalid input. Please enter a number.")
            except Exception as e:
                print(f"Error: {e}")
                print("Returning to main menu...")



    


    display_menu_options()
    menu_system()


init()