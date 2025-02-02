import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

s = "codeforces"

def solve():
    c = input()
    if c in s:
        print("YES")
    else:
        print("NO")

for _ in range(rint()):
    solve()