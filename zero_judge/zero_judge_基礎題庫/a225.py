while True:
    try:
        intmp = int(input())
        inarr = []
        intmp2 = input().split()
        for i in range(intmp):
            inarr.append(int(intmp2[i]))

        inarr.sort(key=lambda x: (x % 10, -x))

        print(" ".join(map(str, inarr)))

    except EOFError:
        break