while True:
    try:
        intmp = input().split()
        n = []
        ans = 0

        for i in range(int(intmp[0])):
            n.append(int(intmp[i+1]))

        for i in range(len(n)):
            ans += n[i]

        if ans % len(n) != 0:
            ans += len(n)
        ans //= len(n)

        if ans < 60:
            print("yes")
        else:
            print("no")

    except EOFError:
        break