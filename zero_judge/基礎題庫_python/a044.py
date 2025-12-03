while True:
    ans = 0
    try:
        ans = int(input())
        ans = int((ans ** 3 + ans * 5) / 6 + 1)
        print(ans)

    except EOFError :
        break