import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n = rint()
    if n & 1:
        print("Kosuke")
    else:
        print("Sakurako")
    

for _ in range(rint()):
    solve()