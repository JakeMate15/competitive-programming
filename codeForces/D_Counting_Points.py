import sys, math
from random import getrandbits

RANDOM = getrandbits(32)
input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n, m = rvar()
    X = rlist()
    R = rlist()

    cnt = {}
    i = 0
    while i < n:
        xi = X[i] - R[i]
        while xi <= X[i] + R[i]:
            sq = int(math.sqrt(R[i] * R[i] - (xi - X[i]) * (xi - X[i])))
            cnt[xi ^ RANDOM] = max(cnt.get(xi ^ RANDOM, 0), 2 * sq + 1)
            xi += 1
        i += 1
        
    ans = sum(cnt.values())
    print(ans)    

for _ in range(rint()):
    solve()