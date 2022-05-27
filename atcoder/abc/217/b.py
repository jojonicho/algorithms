s = input()
t = input()
u = input()

st = {"ABC", "ARC", "AGC", "AHC"}
st.remove(s)
st.remove(t)
st.remove(u)

print(st.pop())
