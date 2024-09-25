import sys, math

input = lambda: sys.stdin.readline()[:-1]
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve ():
    n = rint()
    
    y0 = {}
    y1 = {}
    cnt0 = 0
    cnt1 = 0

    for _ in range(n):
        x, y = rvar()

        if y == 0:
            if x in y0:
                y0[x] += 1
            else:
                y0[x] = 1
            cnt0 += 1
        else:
            if x in y1:
                y1[x] += 1
            else:
                y1[x] = 1
            cnt1 += 1

    res = 0
    for x in y0:
        if x in y1:
            res += max(0, cnt1 - 1)

        x1 = (x - 1) in y1
        x2 = (x + 1) in y1

        res += int(x1 and x2)

    for x in y1:
        if x in y0:
            res += max(0, cnt0 - 1)

        x1 = (x - 1) in y0
        x2 = (x + 1) in y0

        res += int(x1 and x2)

    print(res)
        
    
for _ in range(rint()):
    solve()