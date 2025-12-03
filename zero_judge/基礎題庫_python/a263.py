import datetime

while True:
    try:
        in1 = list(map(int, input().split()))
        in2 = list(map(int, input().split()))
        dt1 = datetime.datetime(in1[0],in1[1],in1[2])
        dt2 = datetime.datetime(in2[0],in2[1],in2[2])
        print(abs((dt2 - dt1).days))

    except EOFError:
        break