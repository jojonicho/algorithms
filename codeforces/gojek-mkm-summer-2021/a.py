x = [11, 10, 10, 5, 10, 15, 20, 10, 7, 11]


def foo(a, b, i, j):
    k = j
    ct = 0
    while k > i-1:
        if x[k] <= b and not (x[k] <= a):
            ct += 1
        k -= 1
    return ct


print(foo(8, 18, 3, 6))
print(foo(10, 20, 0, 9))
print(foo(8, 18, 6, 3))
print(foo(20, 10, 0, 9))
print(foo(6, 7, 8, 8))
