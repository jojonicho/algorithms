# N coconut trees are planted in a straight line at position x1, x2, ..., xn, with tree height of h1, h2, ..., hn.

# If a tree at position i falls down, other trees in range of [xi + 1, xi + h] will also fall down, creating a domino effect.

# Given two arrays X and H, where X denotes the position of each trees, and H denotes the height of each trees,
# return an array L, where *Li* denotes the *rightmost position of the falling tree(s)* if tree at position *Xi* falls down
X = [1, 2, 6]
H = [5, 3, 1]

X = [5, 6, 9]  # case where distance of left side is longer then in stack
H = [2, 2, 1]  # distance = max(cur[1], distance)


def solve(X, H):
    n = len(X)
    st, ans = [], [0] * n
    for i in range(n - 1, -1, -1):
        dist = X[i] + H[i]
        while st and st[-1][0] <= dist:
            cur = st.pop()
            dist = max(dist, cur[1])
        st.append((X[i], dist))
        ans[i] = dist
    return ans


if __name__ == "__main__":
    print(solve(X, H))
