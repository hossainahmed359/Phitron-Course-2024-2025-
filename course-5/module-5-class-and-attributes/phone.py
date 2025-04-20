# Python class documentation  needs to be read
# https://docs.python.org/3/tutorial/classes.html

class Phone:

    manufacturer = "China"

    def __init__(self,  brand, color, price):
        print("This is a constructor")
        self.price = price
        self.color = color
        self.brand = brand
        self.manufacturer = 'Japan'

    def __repr__(self):
        return f"Phone({self.brand}, {self.color}, {self.price})"

    def print_info(self):
        print(f"This is a {self.brand} phone. It is {self.color} in color and costs {self.price} dollars. manufacturer {self.manufacturer}")

my_phone = Phone("samsung", "blue", 1200)
print(my_phone)
# print(my_phone.manufacturer)
# print(my_phone.brand)
# my_phone.print_info()
