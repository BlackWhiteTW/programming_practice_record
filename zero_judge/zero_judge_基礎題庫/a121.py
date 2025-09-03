import math

def is_prime(n):
    if n < 2:
        return 0
    if n == 2 or n == 3 or n == 5:
        return 1
    if n % 2 == 0:
        return 0
    if n % 3 == 0:
        return 0
    if n % 5 == 0:
        return 0
    for j in range(5, int(math.sqrt(n)) + 1, 6):
        if n % j == 0 or n % (j + 2) == 0:
            return 0
    return 1

while True:
    try:
        intmp = input().split()
        int1 = int(intmp[0])
        int2 = int(intmp[1])
        ans = 0
        for i in range(int1, int2 + 1):
            if is_prime(i):
                ans += 1
        print(ans)
    except EOFError:
        break