n = int(input())
ans = []
while n:
    n -= 1
    n, r = divmod(n, 26)
    ans.append(chr(ord("a") + r))
print("".join(reversed(ans)))
