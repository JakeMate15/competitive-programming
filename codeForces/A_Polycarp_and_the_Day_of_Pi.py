import sys, math

input = lambda: sys.stdin.readline()[:-1]
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    s = input()
    ss = "31415926535897932384626433832795028841971693993751058209749445923078"

    res = 0
    for i in range(len(s)):
        if s[i] != ss[i]:
            break
        res += 1
    print(res)
    

for _ in range(rint()):
    solve()