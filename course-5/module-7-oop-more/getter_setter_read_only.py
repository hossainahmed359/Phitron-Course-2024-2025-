class User:
    def __init__(self, name, age, money) -> None:
        self._name = name
        self._age = age
        self.__money = money

    @property  # getter -> method name becomes useable as property
    def age(self):
        return self._age

    @property  # getter
    def salary(self):
        return self.__money
        
    @salary.setter # setter
    def salary(self, value):
        if value < 0:
            return "salary can not be negative"
        self.__money += value


user_a = User("Anonymous", 31, 1000000)
print(user_a.age)

print(user_a.salary)
user_a.salary = 999
print(user_a.salary)