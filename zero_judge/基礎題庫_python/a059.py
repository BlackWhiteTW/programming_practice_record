import math
ans1 = []

intmp = int(input())

for i in range(intmp):
    ans = 0
    in1 = int(input())
    in2 = int(input())

    for j in range(in1,in2+1):
        if math.sqrt(j).is_integer():
            ans += j

    ans1.append(f"Case {i+1}: {ans}")

for i in ans1:
    print(i)