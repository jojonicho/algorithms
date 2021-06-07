from collections import deque

S = input()

isReversed = False

dq = deque()
for s in S:
    if s == "R":
        isReversed = not isReversed
        continue
    if isReversed:
        dq.appendleft(s)
    else:
        dq.append(s)

if not isReversed:
    st = []
    for c in dq:
        if st and st[-1] == c:
            st.pop()
        else:
            st.append(c)
    print("".join(st))
else:
    st = []
    for c in reversed(dq):
        if st and st[-1] == c:
            st.pop()
        else:
            st.append(c)
    print("".join(st))
