from collections import Counter

n = int(input())
a = []
for i in range(n):
    a.append(input())
b = Counter(a)
m = max(b.values())
for k, v in sorted(b.items()):
    if v == m:
        print(k)
