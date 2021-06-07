# a = ["a", "c", "d", "e", "f", "z"]
A = ["a", "b", "d"]
# a = ["c", "f", "j"]
"""
find the next closest char, circular
"""
x = input()


def find(x, A):
    lo, hi = 0, len(A) - 1
    while lo <= hi:
        mid = lo + (hi - lo) // 2  # hi + lo / 2
        if A[mid] <= x:
            lo = mid + 1
        else:
            hi = mid - 1
    return A[lo % len(A)]


if __name__ == "__main__":
    print(find(x, A))
