# write to file
with open("in.txt", 'w') as f:
	# f.write("1\n")
	# f.write("200000\n")
	# for i in range(int(2e5) -2):
		# f.write("1 ")
	# f.write("-1000000000 ")
	# f.write("1000000000 ")
    f.write("0 0\n")
    f.write("1000000000 1000000000\n")
    f.write("100000\n")
    for i in range(100000):
        f.write("U")
