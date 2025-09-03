a , b , c = map(int,input().split())

d = int(b**2 - ( 4 * a * c))

if d >=0:
    ans1 = int((-b + d**0.5) / (2*a))
    ans2 = int((-b - d**0.5) / (2*a))

if d > 0:
    print(f"Two different roots x1={ans1} , x2={ans2}")
elif d == 0:
    print(f"Two same roots x={ans1}")
else:
    print("No real root")