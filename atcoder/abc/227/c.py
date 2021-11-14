n = int(input())

ans = 0
for a in range(1, n + 1):
    if a * a * a > n:
        break
    for b in range(a, n + 1):
        if a * b * b > n:
            break
        ans += n // a // b - b + 1
        # for c in range(b, int(n / a / b + 1)):
        #     ans += 1

print(ans)
