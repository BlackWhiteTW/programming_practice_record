while True:
    ans = 0
    try:
        intmp = int(input())
        ans = intmp * ( intmp - 1 ) + 2
        print(ans)

    except EOFError :
        break