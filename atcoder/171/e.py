N = int(input())
A = list(map(int, input().split()))
S = 0
for x in A:
    S ^= x
print(S)
for i in range(len(A)):
    A[i] ^= S
print(*A)
