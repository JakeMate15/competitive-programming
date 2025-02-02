import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    a, b = rvar()
    print(3)
    print(b, b, 3 * a - 2 * b)
    
for _ in range(1):
    solve()