innum = int(input())
i = 2
arr = []
ansarr = []
tmp = 1

while innum != 1:
    if innum % i == 0:
        arr.append(i)
        innum //= i
    else:
        i += 1

for i in range(len(arr)):
    if i == len(arr) - 1 or arr[i] != arr[i + 1]:
        if tmp == 1:
            ansarr.append(f"{arr[i]}")
        else:
            ansarr.append(f"{arr[i]}^{tmp}")
        if i != len(arr) - 1:
            ansarr.append(" * ")
        tmp = 1
    else:
        tmp += 1

print("".join(ansarr))