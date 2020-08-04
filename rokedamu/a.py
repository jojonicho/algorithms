# a = ["a", "c", "d", "e", "f", "z"]
a = ["a", "b", "d"]
# a = ["c", "f", "j"]
x = input()

lo = 0
hi = len(a) - 1

while lo <= hi:
    mid = lo + (hi - lo) // 2
    if a[mid] <= x:
        lo = mid + 1
    else:
        hi = mid - 1
if lo >= len(a):
    print(a[0])
else:
    print(a[lo])
