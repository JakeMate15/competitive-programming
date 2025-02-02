import sys, heapq

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n = rint()
    for i in range(n):
        curr = [0] * (i + 1)
        curr[0] = 1
        curr[i] = 1
        print(*curr)
    

for _ in range(rint()):
    solve()