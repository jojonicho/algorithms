from collections import Counter

N = int(input())
A = list(map(int, input().split()))
count = Counter(A)
S = sum(A)

for _ in range(int(input())):
    b, c = map(int, input().split())
    k = count[b]
    count[b] = 0
    count[c] += k
    S += (c - b) * k
    print(S)
