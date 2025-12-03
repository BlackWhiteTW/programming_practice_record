while True:
    try:
        intmp = int(input())
        tmp = list(map(int, input().split()))
        tmp.sort()
        print(" ".join(map(str, tmp)))

    except EOFError:
        break