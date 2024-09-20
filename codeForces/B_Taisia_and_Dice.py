import sys, math

input = lambda: sys.stdin.readline()[:-1]
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    nc = rlist()
    n, s, r = nc[0], nc[1], nc[2]

    res = [r // (n - 1)] * (n - 1) + [s - r]
    rem = s - sum(res)

    for i in range(n - 1):
        if rem == 0:
            break
        x = (s - r) - res[i]
        y = max(min(rem, x), 0)
        res[i] += y
        rem -= x

    print(' '.join(str(i) for i in res))



for _ in range(rint()):
    solve()