alphabet = input()
n = int(input())

S = []
for i in range(n):
    S.append(input())

S.sort(key=lambda word: [alphabet.index(c) for c in word])

for s in S:
    # print([alphabet.index(c) for c in s])
    print(s)
