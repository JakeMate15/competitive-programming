import sys, math

input = lambda: sys.stdin.readline().strip()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def count_occurrences(s, pattern):
    count = 0
    pos = s.find(pattern)
    while pos != -1:
        count += 1
        pos = s.find(pattern, pos + 1)
    return count

def solve():
    n, m = rvar()
    grid = [input() for _ in range(n)]
    
    total_count = 0
    layers = min(n, m) // 2

    for k in range(layers):
        s = ""

        for j in range(k, m - k):
            s += grid[k][j]

        for i in range(k + 1, n - k - 1):
            s += grid[i][m - k - 1]

        if n - k - 1 != k:
            for j in range(m - k - 1, k - 1, -1):
                s += grid[n - k - 1][j]

        if m - k - 1 != k:
            for i in range(n - k - 2, k, -1):
                s += grid[i][k]

        p = s.find('1')
        s = s[p:] + s[:p] if p != -1 else s

        total_count += count_occurrences(s, "1543")

    print(total_count)

for _ in range(rint()):
    solve()
