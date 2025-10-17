import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    l, r = rvar()
    if l == 1 and l == r:
        print(1)
    else:
        print(r - l)

for _ in range(rint()):
    solve()