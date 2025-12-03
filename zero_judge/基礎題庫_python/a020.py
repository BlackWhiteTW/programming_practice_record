intmp = input()

first = {
    "A": 10, "B": 11, "C": 12, "D": 13, "E": 14, "F": 15, "G": 16, "H": 17, "I": 34, "J": 18, "K": 19, "L": 20, "M": 21,
    "N": 22, "O": 35, "P": 23, "Q": 24, "R": 25, "S": 26, "T": 27, "U": 28, "V": 29, "W": 32, "X": 30, "Y": 31, "Z": 33
}

ans = first[intmp[0]] // 10 + (first[intmp[0]] % 10) * 9
for i in range(1, 10):
    if 9 - i >1 :
        ans += int(intmp[i]) * (9 - i)
    else :
        ans += int(intmp[i])

print("real" if ans % 10 == 0 else "fake")