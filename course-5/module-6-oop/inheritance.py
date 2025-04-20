class Gadget:
    def __init__(self, name, price, company) -> None:
        self.name = name
        self.price = price
        self.company = company

# inheritance
class Phone(Gadget):
    def __init__(self, name, price, company, camera) -> None:
        super().__init__(name, price, company)
        self.camera = camera
        self.__user_pin = "1234" # Private attribute -> encapsulation

    def __str__(self) -> str:
        return f"Phone: {self.name}, \nPrice: {self.price},\nCompany: {self.company}, \nCamera: {self.camera}"


# Inheritance
my_phone = Phone("iPhone", 999, "Apple", "12MP")
print("Example of Inheritance", my_phone)
# print(my_phone.__user_pin) # Example of encapsulation, this will give an error

print(issubclass(Phone, Gadget))     # True
print(isinstance(my_phone, Gadget))     # True
print(isinstance(my_phone, Phone))     # True