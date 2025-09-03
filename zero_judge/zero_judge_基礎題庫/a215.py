while True:
    try:
        n , m = map(int, input().split())
        ans , tmp = 1 , n
    
        while True:
            if tmp > m :
                break
            tmp += n + ans
            ans += 1

        print(ans)




    except EOFError:
        break