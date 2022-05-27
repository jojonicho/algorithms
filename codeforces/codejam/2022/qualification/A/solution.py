def solve():
    r, c = [int(x) for x in input().split()]
    print(".."+"+-"*(c-1)+"+")
    print(".."+"|."*(c-1)+"|")
    for i in range(2*r-1):
        if(i%2==0):
            print("+-"*c+"+")
        else:
            print("|."*c+"|")

t = int(input())

for i in range(t):
    print(f"Case #{i+1}:")
    solve()

