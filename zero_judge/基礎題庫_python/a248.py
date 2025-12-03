while True:
    try:
        a, b, N = map(int, input().split())
        ans = a * (10 ** N) // b
        rs = str(ans)

        if len(rs) < N:
            rs = '0' * (N - len(rs)) + rs
        n = rs[:-N] if len(rs) > N else '0'
        m = rs[-N:]
        print(f'{n}.{m}')

    except EOFError:
        break