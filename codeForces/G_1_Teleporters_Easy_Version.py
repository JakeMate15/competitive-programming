import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n, c = rvar()
    a = rlist()

    for i in range(n):
        a[i] += i + 1

    a.sort()

    res = 0
    for i in range(n):
        if c >= a[i]:
            res += 1
            c -= a[i]
        else:
            break

    print(res)
    

for _ in range(rint()):
    solve()