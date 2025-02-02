import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n = rint()
    arr = rlist()

    s = 0
    neg = 0
    mn = sys.maxsize
    for num in arr:
        if num < 0:
            num *= -1
            neg += 1

        s += num
        mn = min(mn, num)

    if neg & 1:
        s -= 2 * mn

    print(s)
    

for _ in range(rint()):
    solve()