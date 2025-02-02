import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    B, C, D = rvar()

    get = lambda x, i: True if x & (1 << i) > 0 else False

    a = 0
    for i in range(64):
        b = get(B, i)
        c = get(C, i)
        d = get(D, i)
        
        if ((not d) and (not c) and b) or (d and c and (not b)):
            print(-1)
            return 0
        
        if (d and (not b)) or ((not d) and b):
            a |= 1 << i

    assert((a | B) - (a & C) == D);

    print(a)
    

for _ in range(rint()):
    solve()