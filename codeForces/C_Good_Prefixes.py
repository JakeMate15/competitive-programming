import sys, math

input = lambda: sys.stdin.readline()[:-1]
rint = lambda: int(input())
rlist = lambda: list(map(int, input().split()))

def solve():
    n = rint()
    arr = list(map(int, input().split()))

    res, mx, s = 0, 0, 0
    for i in arr:
        s += i
        mx = max(mx, i)
        if s - mx == mx:
            res += 1

    print(res)
    

for _ in range(rint()):
    solve()