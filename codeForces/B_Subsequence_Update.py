import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n, l, r = rvar()
    arr = rlist()

    tam = r - l + 1
    left = sum(sorted(arr[:r])[:tam])
    right = sum(sorted(arr[l - 1:])[:tam])

    print(min(left, right))

for _ in range(rint()):
    solve()