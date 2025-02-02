import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    l, r = rvar()
    if l == r:
        print(l)
    else:
        print(2)
    

for _ in range(1):
    solve()