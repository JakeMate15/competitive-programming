import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    x, y, k = rvar()
    z = min(x, y)

    print(f"0 0 {z} {z}")
    print(f"0 {z} {z} 0")
    

for _ in range(rint()):
    solve()