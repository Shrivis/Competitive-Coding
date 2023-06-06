for i in range(int(input())):
    res = []
    p1 = list(map(int, input().split()))
    p2 = list(map(int, input().split()))
    p3 = list(map(int, input().split()))
    for i1, i2, i3 in zip(p1, p2, p3):
        res += [min(i1, i2, i3)]

    print(f'Case #{i+1}:', end=" ")
    if (res[0]+res[1]+res[2]+res[3] < 10**6):
        print('IMPOSSIBLE')
    else:
        if (sum(res)-res[3] > 10**6):
            res[3] = 0
        else:
            res[3] = 10**6 -res[0]-res[1]-res[2]
        if (sum(res)-res[2] > 10**6):
            res[2] = 0
        else:
            res[2] = 10**6 -res[0]-res[1]-res[3]
        if (sum(res)-res[1] > 10**6):
            res[1] = 0
        else:
            res[1] = 10**6 -res[0]-res[2]-res[3]
        for ink in res:
            print(ink, end=" ")
         