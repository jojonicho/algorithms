import re

n = int(input())

for t in range(n):
    m, k = input().split(" ")
    a = []
    myans = []
    for i in range(int(m)):
        cur = input()
        a.append(cur)
    for i in range(int(k)):
        ans = 0
        cur = input()
        for an in a:
            an = str(an)
            ln = len(cur.split(" "))
            ant = an.split(" ")
            if ln == 1:
                if cur in ant:
                    ans += 1
            else:
                for i in range(ln, len(ant) + 1):
                    # print(i - ln, i)
                    # print(" ".join([ant[i - ln], ant[i - 1]]))
                    if " ".join([ant[i - ln], ant[i - 1]]) == cur:
                        ans += 1
                        break
        myans.append(ans)
    print("Case " + str(t + 1) + ":")
    for i in myans:
        print(i)
