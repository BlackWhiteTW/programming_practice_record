import sys

while True:
    try:
        intmp = int(input())
        tmp = []
        runtime = 1
        while intmp > 1 :
            if intmp % 2 == 0 :
                tmp.append(0)
            else:
                tmp.append(1)
            intmp //= 2
        if intmp == 1 :
            tmp.append(1)
        else:
            tmp.append(0)

        print("".join(map(str,tmp[::-1])))

    except EOFError:
        break