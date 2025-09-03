intmp = int(input())

for i in range(intmp):
    intmp2 = (input())
    tmp = 1
    ans = []
    for j in intmp2:
        tmp *= int(j)
    ans.append(tmp)

    for i in ans:
        print(i)