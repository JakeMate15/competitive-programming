import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    k, n = rvar()

    g = lambda x: (x * (x + 1)) // 2
    f = lambda mid: int(abs(2 * g(n + mid) - g(n - 1) - g(n + k - 1)))

    lo, hi = 0, k - 1
    while hi - lo > 4:
        m1 = (lo + hi) // 2
        m2 = m1 + 1

        if f(m1) > f(m2):
            lo = m1
        else:
            hi = m2
    
    ans = f(lo)
    for i in range(lo, hi + 1):
        ans = min(ans, f(i))

    print(ans)
    

for _ in range(rint()):
    solve()