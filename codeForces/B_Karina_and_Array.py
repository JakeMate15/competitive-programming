import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n = rint()
    arr = rlist()
    arr.sort()
    print(max(arr[n - 1] * arr[n - 2], arr[0] * arr[1]))
    

for _ in range(rint()):
    solve()