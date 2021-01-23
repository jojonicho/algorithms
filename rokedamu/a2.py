# Given a sorted character characters letters containing only lowercase letters
# and given a target letter target,
# find the smallest element in the list that is larger than the given target.
letters = ["c", "f", 'j']
target = "d"
# mid = 0 + (2-0)/2 = 1
# f <= j == True
# lo = 2

# mid = 2
# j <= j == True
# lo = 3

# lo == n
# return letters[0]

def find(letters, target):
  n = len(letters)
  lo = 0
  hi = n -1
  while lo <= hi :
    mid = lo + (hi-lo)//2
    if letters[mid] <= target:
      lo = mid + 1
    else:
      hi = mid - 1
  if lo == n:
    return letters[0]
  return letters[lo]

if __name__ == '__main__':
  print(find(letters, target))