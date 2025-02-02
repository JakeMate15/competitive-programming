import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n = rint()
    pot = 1
    while n >= 4:
        pot *= 2
        n //= 4
    print(pot)

for _ in range(rint()):
    solve()