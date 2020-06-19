from collections import Counter

s = input()
cnt = Counter([x for x in s])
print(max(cnt.values()))
