# a = ["a", "c", "d", "e", "f", "z"]
a = ["a", "b", "d"]
# a = ["c", "f", "j"]
x = input()


def find(a, x):
    lo = 0
    hi = len(a) - 1
    # lo <= x <= hi
    while lo <= hi:
    # while lo < hi -> lo <= x < hi
        mid = lo + (hi - lo) // 2
        # <= because were finding upper bound
        if a[mid] <= x:
            lo = mid + 1
        else:
            hi = mid - 1
    if lo == len(a):
        return a[0]
    return a[lo]


if __name__ == "__main__":
    print(find(a, x))

