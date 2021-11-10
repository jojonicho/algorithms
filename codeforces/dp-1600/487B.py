from collections import deque

# f[i] = min(f[k]) + 1 for g[i] - 1 <= k <= i - l
# [g[i], i] is a valid seg
# sliding window of max/min elements
"""
debug qmin (increasing) qmax (decreasing), [-1] is max/min
debug deque([1]) deque([1])
debug deque([1, 2]) deque([2])
debug deque([3]) deque([2, 3])
debug deque([3, 4]) deque([2, 4])
debug deque([3, 4, 5]) deque([5])
debug deque([6]) deque([5, 6])
debug deque([6, 7]) deque([7])

g[i + 1] <= g[i] + 1 so it's also a sliding window minimum problem.
"""


def solve(N, S, L, A):
    qmax, qmin = deque(), deque()

    F = [N + 1] * (N + 1)
    F[0] = 0

    q = deque()

    j = 0  # leftIdx
    for i in range(1, N + 1):
        x = A[i]
        # maintain monotonic queue
        while qmax and A[qmax[-1]] <= x:  # increasing
            qmax.pop()
        qmax.append(i)
        while qmin and A[qmin[-1]] >= x:  # decreasing
            qmin.pop()
        qmin.append(i)

        # increment j until max-min <= S
        while j < i and qmax and qmin and A[qmax[0]] - A[qmin[0]] > S:
            while qmax and qmax[0] <= j:
                qmax.popleft()
            while qmin and qmin[0] <= j:
                qmin.popleft()
            j += 1

        # [j,i] is the longest segment now
        if i >= L:
            # insert i-L
            while q and q[-1][1] >= F[i - L]:
                q.pop()
            q.append((i - L, F[i - L]))
        # j - 1 <= k <= i - L
        while q and q[0][0] < j - 1:
            q.popleft()

        if q:
            F[i] = q[0][1] + 1

    return F[-1] if F[-1] <= N else -1


if __name__ == "__main__":
    N, S, L = (int(_) for _ in input().split())
    A = [0] + [int(_) for _ in input().split()]
    print(solve(N, S, L, A))
