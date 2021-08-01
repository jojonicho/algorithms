rrm = lambda: map(int, raw_input().split())
(n, x), A = rrm(), rrm()

ans = normal = multiplying = multiplied = 0
for a in A:
	multiplied = max(0, normal + a, multiplying + a, multiplied + a)
	multiplying = max(0, x*a, multiplying + x*a, normal + x*a)
	normal = max(0, a, normal+a)
	ans = max(ans, normal, multiplying, multiplied)

print(ans)