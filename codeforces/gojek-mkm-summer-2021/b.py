def g(s):
    i = 0
    new_str = ""
    while i < (len(s) - 1):
        new_str += s[i+1]
        i += 1
    return new_str


def f(s):
    if len(s) == 0:
        return ""
    if len(s) == 1:
        return s
    return f(g(s)) + s[0]


def h(n, s):
    while(n != 1):
        if n % 2 == 0:
            n /= 2
        else:
            n = 3*n + 1
        s = f(s)
    return s


def pow(x, y):
    if y == 0:
        return 1
    return x * pow(x, y-1)


# print(h(1, "fruits"))
# print(h(2, "fruits"))
# print(h(4, "fruits"))
# print(h(8, "fruits"))
# print(h(16, "fruits"))
# print(h(32, "fruits"))
# print(h(64, "fruits"))
# print(h(128, "fruits"))
# print(h(256, "fruits"))
def bob(x):
    if x % 2 == 0:
        return "fruits"
    else:
        return "stiurf"


print(bob(0))
print(bob(7))
# print(bob(2))
# print(bob(3))
# print(bob(4))
# print(bob(5))
# print(bob(6))
# print(bob(7))
print(bob(8))

# print(h(3, "fruits"))
# print(h(4, "fruits"))
# print(h(5, "fruits"))
# print(h(6, "fruits"))
# print(h(7, "fruits"))
# print(h(8, "fruits"))
# print(pow(2, 2))

# print(pow(2, 1e15))

# print(h(pow(2, 1e15), "fruits"))
# print(h(pow(2, 9831050005000007), "fruits"))
