intmp = int(input())
ans = 0

if intmp <= 10:
    ans = intmp * 6
elif intmp <= 20:
    ans = 60 + (intmp - 10) * 2
elif intmp < 40:
    ans = 80 + (intmp - 20) * 1
else:
    ans = 100

print(ans)