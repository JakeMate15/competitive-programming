import sys, math

input = lambda: sys.stdin.readline()[:-1]
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    a, b = rvar()

    if a % 2 == 0 and (a > 0 or b % 2 == 0):
        print('YES')
    else:
        print('NO')
    

for _ in range(rint()):
    solve()