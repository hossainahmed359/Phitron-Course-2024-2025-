# Example of Polymorphism
class Animal:
    def __init__(self, name) -> None:
        self.name = name

    def sound(self):  # Abstract method
        print("Animal sound")
        pass


class Cat(Animal):
    def __init__(self, name) -> None:
        super().__init__(name)

    def sound(self):  # Overriding the abstract method
        print(f"{self.name} says Animal")
        pass

class Dog(Animal):
    def __init__(self, name) -> None:
        super().__init__(name)

    def sound(self):  # Overriding the abstract method
        print(f"{self.name} says Bark!")
        pass


cat = Cat("Tom")
dog = Dog("Husky")

cat.sound()  # Output: Tom says Meow!
dog.sound()  # Output: Tom says Meow!