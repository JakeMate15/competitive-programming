import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    x, y = rvar()
    rem = x - y + 1
    print("Yes" if rem % 9 == 0 and rem >= 0 else "No")

for _ in range(rint()):
    solve()