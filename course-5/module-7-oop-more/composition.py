# has a relation

class Engine:
    def __init__(self) -> None:
        pass

    def start(self):
        return "Engine Started"


class Driver:
    def __init__(self) -> None:
        pass


class Car:
    def __init__(self) -> None:
        self.engine = Engine()
        self.driver = Driver()

    def start(self):
        return self.engine.start()


new_car = Car()
print(new_car.start())

# uml diagram
# design pattern