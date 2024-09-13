import sys, math

input = lambda: sys.stdin.readline()[:-1]
rint = lambda: int(input())
rlist = lambda: list(map(int, input().split()))

def solve():
    l, r, k = map(int,input().split())

    x = 9 // k + 1
    mod = 10**9 + 7
    print((pow(x, r, mod) - pow(x, l, mod)) % mod)
    

for _ in range(rint()):
    solve()