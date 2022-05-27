S, E = 1, 101
for i in range(S, E):
    for j in range(S, E):
        for k in range(S, E):
            for l in range(S, E):
                A = [i, j, k, l]
                n = len(A)
                ok = 1
                for a in range(n):
                    for b in range(a):
                        if sum(A[b : a + 1]) != (A[a] + A[b]) / 2 * (a - b + 1):
                            ok = 0
                            break
                if ok:
                    print(A)
