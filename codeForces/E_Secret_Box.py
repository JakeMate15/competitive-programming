import sys, math

input = lambda: sys.stdin.readline()[:-1]
rint = lambda: int(input())
rlist = lambda: list(map(int, input().split()))

def solve():
    x, y, z, k = map(int, input().split())

    divs = []
    i = 1
    while i * i <= k:
        if k % i == 0:
            divs.append(i)
            if k // i != i:
                divs.append(k // i)
        i += 1

    res = 0
    for xi in divs:
        if xi > x:
            continue
        for yi in divs:
            if yi > y or k % (xi * yi) != 0 or k // (xi * yi) > z:
                continue
            zi = k // (xi * yi)
            if xi * yi * zi == k:
                curr = (x - xi + 1) * (y - yi + 1) * (z - zi + 1)
                res = max(res, curr)
    print(res)
    

for _ in range(rint()):
    solve()