def f(ff:int , ft:int):
    ff = ft * (ft + 1) // 2
    return ff

def g(gg:int , gt:int):
    while gt > 0:
        gg += f(0, gt)
        gt -= 1
    return gg

while True:
    try:
        intmp = int(input())
        ans = []
        ans.append(f(0,intmp))
        ans.append(g(0,intmp))
        print(" ".join(map(str,ans)))

    except EOFError:
        break