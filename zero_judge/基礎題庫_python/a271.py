rt = int(input())

def die_check(m):
    if m <= 0:
        print("bye~Rabbit")
        return True
    return False

for i in range(rt):
    x , y , z , w , n , m = map(int, input().split())

    run = input().split()
    vemon = 0 

    list1 = {'1': x, '2': y, '3': -z, '4': -w}

    for j in run:
        m -= vemon * n
        if die_check(m):
            break
        if j in list1:
            m += list1[j]
        if j == '4':
            vemon += 1
        if die_check(m):
            break
    else:
        print(f"{m}g")