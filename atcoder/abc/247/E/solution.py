N, X, Y = map(int, input().split())
A = list(map(int, input().split()))

__, X_, _Y, XY = [1] * N, [1] * N, [1] * N, [1] * N

def f(S):
    S.append(0)
    ans, cnt = 0, 0
    for x in S:
        if x == 1:
            cnt += 1
        else:
            # 1 1 1 1 1 -> 5 + 4 + 3 + 2 + 1 -> n * (n+1) // 2
            ans += cnt * (cnt + 1) // 2
            cnt = 0
    return ans

for i in range(N):
    if not (Y <= A[i] and A[i] <= X):
        __[i] = X_[i] = _Y[i] = XY[i] = 0
    if A[i] == X:
        X_[i] = XY[i] = 0
    if A[i] == Y:
        _Y[i] = XY[i] = 0

print(f(__) - f(X_) - f(_Y) + f(XY))
