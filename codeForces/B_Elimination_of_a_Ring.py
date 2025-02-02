import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n = rint()
    print(n // 2 + 1 if len(set(rlist())) == 2 else n)
    

for _ in range(rint()):
    solve()