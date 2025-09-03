intmp = int(input())
a , b , c = 0 , 0 , 0
for i in range(intmp):
    intmp2 = int(input())
    if intmp2 % 3 == 0:
        a += 1
    elif intmp2 % 3 == 1:
        b += 1
    else:
        c += 1

print(a, b, c)