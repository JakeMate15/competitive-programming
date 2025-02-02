import sys, math, bisect

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n, k, q = rvar()
    a = [[] for _ in range(k)]
    for _ in range(n):
        vals = list(rvar())
        for j in range(k):
            a[j].append(vals[j])
    b = [[0]*n for _ in range(k)]
    for j in range(k):
        current_or = 0
        for i in range(n):
            current_or |= a[j][i]
            b[j][i] = current_or
    for _ in range(q):
        m = rint()
        lower_i = 1
        upper_i = n
        no_solution = False
        for req in range(m):
            parts = input().split()
            r = int(parts[0])
            o = parts[1]
            c = int(parts[2])
            region = r -1
            if o == '<':
                pos = bisect.bisect_left(b[region], c)
                if pos ==0:
                    no_solution = True
                    for _ in range(m - req -1):
                        dummy = input()
                    break
                else:
                    upper_i = min(upper_i, pos)
            elif o == '>':
                pos = bisect.bisect_right(b[region], c)
                if pos ==n:
                    no_solution = True
                    for _ in range(m - req -1):
                        dummy = input()
                    break
                else:
                    lower_i = max(lower_i, pos +1)
        if no_solution or lower_i > upper_i:
            print("-1")
        else:
            print(lower_i)

for _ in range(1):
    solve()
