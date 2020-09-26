# n = int(input())
# q = int(input())
n, q = [int(i) for i in input().split()]
m = 998244353
s = [1] * n

for i in range(q):
    l, r, d = [int(c) for c in input().split()]
    l -= 1
    # for (int j = l; j <= r; j++):
    for j in range(l, r):
        s[j] = d
    print(int("".join(s)) % m)