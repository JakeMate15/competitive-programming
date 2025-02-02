import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n = rint()
    a = rlist()

    lst, ans = -1, n
    for i in range(n):
        if a[i] != a[0]:
            ans = min(ans, i - lst - 1)
            lst = i
    
    ans = min(ans, n - lst - 1)
    print(-1 if ans == n else ans)

for _ in range(rint()):
    solve()