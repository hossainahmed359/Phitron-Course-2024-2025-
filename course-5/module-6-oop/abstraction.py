from abc import ABC, abstractmethod
# abc -> abstract base class

#abstract base class
class Shape(ABC):
    @abstractmethod
    def area(self):
        pass

    @abstractmethod
    def perimeter(self):
        pass

class Circle(Shape):
    def __init__(self, radius) -> None:
        self.radius = radius

    def area(self):
        return 3.14 * self.radius ** 2

    def perimeter(self):
        return 2 * 3.14 * self.radius

circle = Circle(5)
print("Example of Abstraction: ", circle.area()) # 78.5


