intmp = input()

intmp = intmp.split()

if intmp[1] == '+':
    print(int(intmp[0]) + int(intmp[2]))
elif intmp[1] == '-':
    print(int(intmp[0]) - int(intmp[2]))
elif intmp[1] == '*':
    print(int(intmp[0]) * int(intmp[2]))
else:
    print(int(intmp[0]) // int(intmp[2]))