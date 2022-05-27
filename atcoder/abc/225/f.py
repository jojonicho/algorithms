# input two ints
n, k = map(int, input().split())


def solve(A):
    for i in range(n):
        for j in range(i + 1, n):
            if A[i] + A[j] > A[j] + A[i]:
                A[i], A[j] = A[j], A[i]

    return "".join(A[:k])


A = []
for i in range(n):
    s = input()
    A.append(s)
A.sort()

print(solve(A))
