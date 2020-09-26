n = int(input())
for i in range(n):
    s = input().split()
    x = int(s[0])
    y = int(s[1])
    if y * 2 <= x + y:
        print("Voting Ulang")
    elif x < y:
        print("Toni")
    else:
        print("Tere")
