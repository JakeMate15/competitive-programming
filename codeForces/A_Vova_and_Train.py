import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    L, v, l, r = rvar()
    ans = L // v
    ans -= r // v - (l - 1) // v

    print(ans)

for _ in range(rint()):
    solve()