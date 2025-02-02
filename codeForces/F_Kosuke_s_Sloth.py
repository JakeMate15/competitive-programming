import sys

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

MOD = int(1e9 + 7)
MX = int(1e7)

mp = {}
def get(k):
    if k in mp:
        return mp[k]
    
    if k == 1:
        mp[k] = 1
        return 1
    
    f0, f1 = 0, 1
    for i in range(2, MX + 1):
        aux = (f0 + f1) % k
        f0, f1 = f1, aux
        if aux == 0:
            mp[k] = i
            return i
    
    mp[k] = -1
    return -1

def solve():
    n, k = rvar()
    
    if k == 1:
        print(n % MOD)
        return
    
    D = get(k)
    assert D != -1
    print(n * D % MOD)


t = 1
t = rint()
for _ in range(t):
    solve()
