n = int(input())
P = [int(x) for x in input().split(" ")]

A = [0] * n
for i in range(n):
    A[P[i] - 1] = i + 1

for x in A:
    print(x, end=" ")
