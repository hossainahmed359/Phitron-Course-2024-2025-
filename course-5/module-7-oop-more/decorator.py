# function is a first class object in python

# my_callback_func(callback)() -> outout of callback

def my_callback_func(callback) :
    callback()
    print('my_callback_func End')

@my_callback_func
def callback() :
    print('Calling the callback')



def star(func):
    def inner(*args, **kwargs):
        print("*" * 15)
        func(*args, **kwargs)
        print("*" * 15)
    return inner


def percent(func):
    def inner(*args, **kwargs):
        print("%" * 15)
        func(*args, **kwargs)
        print("%" * 15)
    return inner


@star
@percent
def printer(msg):
    print(msg)

printer("Hello")