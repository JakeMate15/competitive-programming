import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

n, k = rvar()
ways = k
for i in range(1, n):
    ways *= (k - 1)

print(ways)