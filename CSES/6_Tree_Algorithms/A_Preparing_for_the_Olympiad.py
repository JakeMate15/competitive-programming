import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n = rint()
    a = rlist()
    b = rlist()
    
    b.append(0)
    ans = 0
    for i in range(n):
        ans += max(0, a[i] - b[i + 1])
    print(ans)

for _ in range(rint()):
    solve()