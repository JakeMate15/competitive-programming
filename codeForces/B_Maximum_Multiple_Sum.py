import sys, math

input = lambda: sys.stdin.readline()[:-1]
rint = lambda: int(input())
rlist = lambda: list(map(int, input().split()))

def solve():
    n = rint()
    res = 2
    
    s = lambda n, x: x * (n // x * (n // x + 1)) // 2
    curr = s(n, 2)

    for x in range(3, n + 1):
        cs = s(n, x)
        if cs > curr:
            curr = cs
            res = x

    print(res)
    

for _ in range(rint()):
    solve()