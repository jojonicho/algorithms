x = 11
for i in range(1, 11):
    if x % 2 == 0:
        x -= i
        print("LEFT")
    else:
        x += i
        print("RIGHT")
    print(i, x)
