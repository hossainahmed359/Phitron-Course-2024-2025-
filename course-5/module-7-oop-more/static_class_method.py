class Shopping:
    cart = []  # static attribute,

    def __init__(self, name, location) -> None:
        self.name = name
        self.location = location

    @classmethod
    def print_cart(self):
        print("classmethod", self.cart)

    @staticmethod
    def multiply_nums(a, b):
        print("staticmethod", a * b)


Shopping.print_cart()
Shopping.multiply_nums(1, 3)
