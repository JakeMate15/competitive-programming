import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n = rint()
    s = input()[:-1]

    arr = [[0] * 26 for _ in range(n + 1)]
    for i in range(1, n + 1):
        p = ord(s[i - 1]) - ord('a')
        arr[i][p] += 1
        
        for j in range(26):
            arr[i][j] += arr[i - 1][j]

    ans = 0
    for i in range(1, n + 1):
        l = 0
        r = 0
        for j in range(26):
            if arr[i][j] > 0:
                l += 1

            if arr[n][j] - arr[i][j] > 0:
                r += 1

        ans = max(ans, l + r)

    print(ans)    
    

for _ in range(rint()):
    solve()