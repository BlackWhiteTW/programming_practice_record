while True:
    intmp = input()

    if intmp == '0':
        break

    for i in range(1, int(intmp)):
        if i % 7 != 0:
            print(i, end=' ')
    print()