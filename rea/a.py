DOWN = "0"


def jumlah_dolby_ditelpon(s):
    # 5 menit berturut turut
    minutes_down = 0
    phone_count = 0
    for c in s:
        if c == DOWN:
            minutes_down += 1
        else:
            if minutes_down >= 5:
                phone_count += 1
            minutes_down = 0
    if minutes_down >= 5:
        phone_count += 1
    return phone_count


if __name__ == "__main__":
    # read from file
    f = open("down_detector_big_case_input.txt", "r")
    # f = open("coding-down-detector-small_case.txt", "r")
    t = int(f.readline())
    for i in range(t):
        s = f.readline().split(" ")[1:]
        with open("out-2.txt", "a") as txt:
            txt.write(f"Case #{i+1}: {jumlah_dolby_ditelpon(s)}\n")
