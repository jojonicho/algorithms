import itertools

s = input()
s = set(itertools.permutations(s))
print(len(s))
