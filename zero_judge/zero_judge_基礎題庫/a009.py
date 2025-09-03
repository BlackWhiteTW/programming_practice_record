instr = input()
strans = ""
for ch in instr:
    ans = int(ord(ch) - 7)
    strans += chr(ans)

print(strans)