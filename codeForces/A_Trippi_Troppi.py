import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    ss = list(input().split())
    for s in ss:
        print(s[0], end='')
    print()    

for _ in range(rint()):
    solve()