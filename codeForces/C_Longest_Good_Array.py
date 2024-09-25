import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    l, r = rvar()

    g = lambda x: x * (x + 1) // 2

    tam = r - l
    lo = -1
    hi = 100000
    while lo + 1 < hi:
        mid = (lo + hi) // 2
        s = g(mid)

        if s <= tam:
            lo = mid
        else:
            hi = mid
    
    print(hi)
    
for _ in range(rint()):
    solve()