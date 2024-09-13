import sys, math

input = lambda: sys.stdin.readline()[:-1]
rint = lambda: int(input())
rlist = lambda: list(map(int, input().split()))

def solve():
    a, b = input().split()
    print(b[0] + a[1:], a[0] + b[1:])
    

for _ in range(rint()):
    solve()