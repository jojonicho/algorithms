n = int(input())
prev = 7
cnt = 0
bad = 1
for i in range(1, 1000001):
    if i > 1:
        prev = prev * 10 + 7
    cnt += 1
    if prev % n == 0:
        bad = 0
        print(cnt)
        break
if bad:
    print(-1)
