intmp = input()

ans = True

for i in range(0, len(intmp)//2+1):
    if intmp[i] != intmp[len(intmp)-1-i]:
        ans = False

print("yes" if ans else "no")