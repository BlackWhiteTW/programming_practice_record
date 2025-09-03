intmp = input()
ans =[]

for i in range(1,len(intmp)):
    ans.append(str(abs(ord(intmp[i]) - ord(intmp[i-1]))))


print("".join(ans))