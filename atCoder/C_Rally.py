import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

n = rint()
positions = rlist()

ans = 1000000
for P in range(1, 101):
    current = 0
    for p in positions:
        current += (P - p) * (P - p)
    ans = min(ans, current)
print(ans)
