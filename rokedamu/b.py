# n = int(input())
# for
n = 3
# x = [5, 6, 9]
# h = [2, 2, 1]
x = [1, 2, 6]
h = [5, 3, 1]


def find_falling_trees(x, h):
    trees = list(zip(x, h))
    ans = [0] * n
    st = []
    last = 0
    for i in range(n - 1, -1, -1):
        curpos = x[i] + h[i]
        # if i == n - 1:
        #     ans[i] = curpos
        #     st.append([x[i], curpos])
        #     continue
        while st and curpos >= st[-1][0]:
            curpos = max(curpos, st.pop()[1])
        st.append([x[i], curpos])
        ans[i] = curpos
    return ans


if __name__ == "__main__":
    # print(trees)
    print(find_falling_trees(x, h))

