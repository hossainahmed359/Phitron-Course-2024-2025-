class Person:
    def __init__(self, name, age, height, weight) -> None:
        self.name = name
        self.age = age
        self.height = height
        self.weight = weight

    def eat(self):
        print("User eats food")

    def exercise(self):
        raise NotImplementedError


class Cricketer(Person):
    def __init__(self, name, age, height, weight, team) -> None:
        self.team = team
        super().__init__(name, age, height, weight)

    # Override
    def eat(self):
        print("User eats healthy food only")

    # Override
    def exercise(self):
        print("Do the exercise")

    # Overload // dunder methods // operator overload
    def __add__(self, other):
        return self.height + other.height
    # Overload
    def __mul__(self, other):
        return self.height * other.height + 10

playerA = Cricketer("PlayerA", 20, 6, 80, "Phitron");
playerB = Cricketer("PlayerB", 18, 5, 70, "Phitron");

playerA.eat()
playerA.exercise()


print(playerA + playerB)
print(playerA * playerB)