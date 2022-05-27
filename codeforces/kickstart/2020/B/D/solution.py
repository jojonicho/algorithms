from scipy.stats import binom


str_in = input()

def solve(w,h,l,u,r,d):
    res = 0
    if u-2 >= 0 and w > r:
        res += binom.cdf(u-2, r+u-2, 0.5)
    if l-2 >= 0 and h > d:
        res += binom.cdf(l-2, d+l-2, 0.5)
    
    return res

for case in range(int(str_in)):
    w,h,l,u,r,d = [int(x) for x in input().split()]
    ans = solve(w,h,l,u,r,d)
    
    print("Case #{}: {}".format(case + 1, ans))

