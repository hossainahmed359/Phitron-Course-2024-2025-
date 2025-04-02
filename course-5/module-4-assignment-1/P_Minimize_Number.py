# https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/P
# P. Minimize Number

n = int(input())
lst = str(input()).split(" ")

for i in range(n) :
    lst[i] = int(lst[i])

count = 0

flag = True

while flag:
    for i in range(n):
        if lst[i] % 2 == 0:
            lst[i] = lst[i] / 2
        else: 
            flag = False
            break;

    # break condition
    if flag is False:
        break

    count += 1

print(count)
