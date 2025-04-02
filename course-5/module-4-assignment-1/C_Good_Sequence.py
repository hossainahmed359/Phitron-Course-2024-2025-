# https://atcoder.jp/contests/arc087/tasks/arc087_a
# C - Good Sequence

n = int(input())
lst = list(map(int, input().split()))
freq = {}

for x in lst:
    if x not in freq:
        freq[x] = 1
    else:
        freq[x] += 1

remove_count = 0

for key, value in freq.items():
    if value > key:
        remove_count += value - key
    elif value < key:
        remove_count += value

print(remove_count)