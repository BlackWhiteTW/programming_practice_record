while True:
    try:
        a = list(map(int, input().split()))
        rt = int(input())

        for _ in range(rt):
            b = list(map(int, input().split()))
            tmpa = 0
            tmpb = 0

            for i in range(len(a)):
                if a[i] == b[i]:
                    tmpa += 1
                elif b[i] in a:
                    tmpb += 1

            print(f"{tmpa}A{tmpb}B")
    except EOFError:
        break