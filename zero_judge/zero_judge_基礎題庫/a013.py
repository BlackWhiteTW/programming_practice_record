strl = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500,
    'M': 1000
}

def int_to_roman(num):
    val = [
        1000 , 900 , 500 , 400 , 100 , 90 , 50 , 40 , 10 , 9 , 5 , 4 , 1
    ]
    syb = [
        "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
    ]
    roman_num = ""
    for i in range(len(val)):
        while num >= val[i]:
            roman_num += syb[i]
            num -= val[i]
    return roman_num

def roman_to_int(str):

    arr=[strl[str[i]] if str[i] in strl else 0 for i in range(len(str))]

    for i in range(len(arr)-1):
        if arr[i] < arr[i+1]:
            arr[i] = -arr[i]

    tmp_int = sum(arr)

    return tmp_int

while True:

    inarr = input()
    if inarr == "#":
        break
    str_a, str_b = inarr.split()

    ans = abs(roman_to_int(str_a) - roman_to_int(str_b))
    if ans != 0:
        print(int_to_roman(ans))
    else:
        print("ZERO")