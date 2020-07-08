b = {}
for _ in range(int(input())):
    s = input()
    b[s] = b.get(s, 0) + 1
m = max(b.values())
print(*sorted(k for k in b if b[k] == m))

