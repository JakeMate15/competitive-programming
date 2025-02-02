import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n = rint()
    s = input()

    l = 0
    r = n - 1
    while l < r and s[l] != s[r]:
        l += 1
        r -= 1

    print(r - l + 1)
    

for _ in range(rint()):
    solve()