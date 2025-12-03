while True:

    try:
        intmp = input()
        r , c = map(int, intmp.split())

        arr = [[0 for j in range(c)] for i in range(r)]

        for i in range(0, r):
            intmp = input()
            arr_tmp = intmp.split()
            for j in range(0, c):
                arr[i][j] = int(arr_tmp[j])

        for i in range(0, c):
            for j in range(0, r):
                print(arr[j][i], end=" ")
            print()

    except EOFError:
        break