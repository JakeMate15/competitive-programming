import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n = rint()
    mat = [rlist() for _ in range(n)]
    
    ans = 0
    i = 0
    while i < n:
        curr = 0
        ii = 0
        j = i
        while ii < n and j < n:
            # print(ii, j)
            curr = min(curr, mat[ii][j])
            ii += 1
            j += 1
        ans += curr

        ii = i + 1
        j = 0
        curr = 0
        while ii < n and j < n:
            # print(ii, j)
            curr = min(curr, mat[ii][j])
            ii += 1
            j += 1
        ans += curr
        i += 1

    print(-ans)

for _ in range(rint()):
    solve()
