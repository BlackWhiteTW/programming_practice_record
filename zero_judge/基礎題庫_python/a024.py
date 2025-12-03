intmp = input()

intmp = intmp.split()

a = int(intmp[0])
b = int(intmp[1])

while a != 0 and b != 0:
    if a > b:
        a = a % b
    else:
        b = b % a

print(a + b)