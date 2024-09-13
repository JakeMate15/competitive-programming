import sys, math

input = lambda: sys.stdin.readline()[:-1]
rint = lambda: int(input())
rlist = lambda: list(map(int, input().split()))

def solve():
    h, n = map(int, input().split())
    d = rlist()
    c = rlist()

    lo, hi = 0, int(1E11)
    while lo + 1 < hi:
        mid = (lo + hi) // 2

        s = 0
        for i in range(n):
            s += math.ceil(mid / c[i]) * d[i]
            if s >= h:
                break

        if s >= h:
            hi = mid
        else:
            lo = mid

    print(hi)
    

for _ in range(rint()):
    solve()