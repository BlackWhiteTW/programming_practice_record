intmp = input().split()

ans = []
for i in range(int(intmp[0]), int(intmp[1])):
    strtmp = str(i)
    tmp = 0
    for j in strtmp:
        tmp += int(j) ** (len(strtmp))
    if tmp in range(int(intmp[0]), int(intmp[1])) and tmp == i:
        ans.append(i)

if len(ans) == 0:
    print("none")
else:
    print(*ans)