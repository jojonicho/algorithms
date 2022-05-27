for _ in range(int(input())):
    n = int(input())
    for i in range(n):
        print("(" * (n - i) + ")" * (n - i) + "(" * i + ")" * i)
