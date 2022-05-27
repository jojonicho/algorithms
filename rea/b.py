def pair_programming(s, t):
    # 5 menit berturut turut
    A = [(int(s[i]), s[i + 1]) for i in range(0, len(s), 2)]
    A.extend([(int(t[i]), t[i + 1]) for i in range(0, len(t), 2)])
    A.sort()
    return "".join([c for (idx, c) in A])


if __name__ == "__main__":
    # read from file
    f = open("pairprogramming_big_case_input.txt", "r")
    # f = open("coding-pair-programming-small_case.txt", "r")
    T = int(f.readline())
    # T = int(input())
    for i in range(T):
        # s = input().split()
        # t = input().split()
        # print(f"Case #{i+1}: {pair_programming(s, t)}\n")
        s = f.readline().split()
        t = f.readline().split()
        with open("out-b2.txt", "a") as txt:
            txt.write(f"Case #{i+1}: {pair_programming(s, t)}\n")
