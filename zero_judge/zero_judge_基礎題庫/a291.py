while True:
    try:
        a = list(map(int, input().split()))
        rt = int(input())
        for i in range(rt):
            tmpa = 0
            tmpb = 0
            b = list(map(int, input().split()))
            for j in range(0,len(a)):
                if b[j] == a[j]:
                    tmpa += 1
                    continue
                elif b[j] in a:
                    tmpb += 1
                    continue
            print(f"{tmpa}A{tmpb}B")
    except EOFError:
        break