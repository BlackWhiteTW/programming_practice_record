q = int(input())
for _ in range(q):
    a , b , c , d = map(int, input().split())
    if b - a == c - b == d - c:
        e = d + (d - c)
    elif b // a == c // b == d // c:
        e = d * (d // c)
    print(f"{a} {b} {c} {d} {e}")