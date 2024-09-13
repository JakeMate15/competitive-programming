import sys, math

input = lambda: sys.stdin.readline()[:-1]
rint = lambda: int(input())
rlist = lambda: list(map(int, input().split()))

def solve():
    n, m = map(int, input().split())

    g = [input() for i in range(n)]
    
    x1, x2, y1, y2 = 1000001, 0, 1000001, 0
    for i in range(n):
        for j in range(m):
            if g[i][j] == '#':
                x1 = min(x1, i)
                x2 = max(x2, i)
                y1 = min(y1, j)
                y2 = max(y2, j)

    print((x1 + x2) // 2 + 1, (y1 + y2) // 2 + 1)
    

for _ in range(rint()):
    solve()