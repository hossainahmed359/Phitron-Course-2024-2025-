# https://codeforces.com/group/MWSDmqGsZm/contest/219856/problem/S?fbclid=IwAR1qi6o8WBDOrdzcZ--U5YO_40SSQmmLbZ8jggB6CFIRqog1ukVL_Z2wK2s
# S. Max Split

input_str = input()

def balance_str(input_str):
    lst = []
    tmp = ""
    balance = 0

    for x in input_str:
        tmp += x

        if x == "R":
            balance += 1
        else:
            balance -= 1

        if balance == 0:
            lst.append(tmp)
            tmp = ""

    return lst

balance_str_lst = balance_str(input_str)

print(len(balance_str_lst))

for x in balance_str_lst:
    print(x)
