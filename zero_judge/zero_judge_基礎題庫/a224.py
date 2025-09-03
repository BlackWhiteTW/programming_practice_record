while True:
    try:
        intmp = input().lower()
        tmpb = 0
        tmp = ""
        tmpa = []
        tmpc = 0

        for i in range(len(intmp)):
            if intmp[i].isalpha() and intmp[i] not in tmp:
                tmp += intmp[i]
                tmpa.append(1)
                tmpb += 1

            elif intmp[i].isalpha() and intmp[i] in tmp:
                tmpa[tmp.index(intmp[i])] += 1
                tmpb += 1

        if tmpb % 2 == 0:
            for i in tmpa:
                if i % 2 != 0:
                    print("no...")
                    break
            else:
                print("yes !")
        else:
            for i in tmpa:
                if i % 2 != 0:
                    tmpc += 1
            if tmpc == 1:
                print("yes !")
            else:
                print("no...")

    except EOFError:
        break