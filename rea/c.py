from collections import defaultdict, deque


def count_referrals(user_to_referrals):
    # 5 menit berturut turut
    q = deque()
    q.append(1)
    points = 0
    while len(q):
        u = q.popleft()
        for v in user_to_referrals[u]:
            points += 1
            q.append(v)
    return points


if __name__ == "__main__":
    # read from file
    # f = open("coding-referral-small_case.txt", "r")
    f = open("referral_big_case_input.txt", "r")
    T = int(f.readline())
    # T = int(input())
    for i in range(T):
        # print(f"Case #{i+1}: {pair_programming(s, t)}\n")
        n = int(f.readline())
        user_to_referrals = defaultdict(list)
        for j in range(n):
            # input two integers
            u, v = [int(x) for x in f.readline().split()]
            user_to_referrals[u].append(v)
        with open("out-c2.txt", "a") as txt:
            txt.write(f"Case #{i+1}: {count_referrals(user_to_referrals)}\n")
