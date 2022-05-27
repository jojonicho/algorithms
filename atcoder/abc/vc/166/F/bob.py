A = [[1,3],[2,3],[3,3]]
n = len(A)
prvM = -1
ans = 0
for i in range(1, n) :
    m = (A[i][1] - A[i-1][1]) / (A[i][0] - A[i-1][0])
    if i == 1:
        prvM = m;
        continue
    if(m == prvM):
        ans+=1
    print(prvM, m)
    prvM = m

print(ans)
