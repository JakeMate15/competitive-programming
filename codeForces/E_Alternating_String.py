import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve ():
    n = rint()
    s = input()

    cnt = [[[0 for _ in range(2)] for _ in range(26)] for _ in range(n + 5)]

    for i in range(1, n + 1):
        cnt[i][ord(s[i - 1]) - ord('a')][i % 2] += 1

    for i in range(2):
        for j in range(26):
            for k in range(1, n + 1):
                cnt[k][j][i] += cnt[k - 1][j][i]

    res = 200000 + 5

    if n % 2 == 1:
        for i in range(1, n + 1):
            pa = 0
            im = 0
            for c in range(26):
                pa = max(pa, cnt[i - 1][c][0] + cnt[n][c][1] - cnt[i][c][1])
                im = max(im, cnt[i - 1][c][1] + cnt[n][c][0] - cnt[i][c][0])

            res = min(res, n - pa - im)
    else:
        mx1 = 0
        mx2 = 0
        for i in range(26):
            mx1 = max(mx1, cnt[n][i][0])
            mx2 = max(mx2, cnt[n][i][1])
        res = n - mx1 - mx2

    print(res)

for _ in range(rint()):
    solve()