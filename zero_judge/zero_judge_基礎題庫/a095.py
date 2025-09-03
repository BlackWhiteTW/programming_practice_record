while True:
    try:
        intmp = input().split()
        ans = int(intmp[1])
        if intmp[0] != intmp[1]:
            ans += 1

        print(ans)

    except EOFError:
        break