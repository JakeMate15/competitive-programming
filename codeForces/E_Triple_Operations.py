import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

mx = (2 * 10**5 + 5)
lg = [0] * mx

def solve():
    l, r = rvar()
    ans = lg[r] - 2 * lg[l - 1] + lg[l]
    print(ans)
    

for i in range (1, mx):
    n = i
    while n > 0:
        n //= 3
        lg[i] += 1

    lg[i] += lg[i - 1]

for _ in range(rint()):
    solve()