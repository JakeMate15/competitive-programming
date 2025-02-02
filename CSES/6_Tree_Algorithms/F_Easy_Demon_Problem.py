import sys, bisect
from functools import lru_cache

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

@lru_cache(maxsize=None)
def divisores(x):    
    X = abs(x)
    d = []
    
    i = 1
    while i * i <= X:
        if X % i == 0:
            d.append(i)
            if i != X // i:
                d.append(X // i)
        i += 1        
    
    d += [-x for x in d]
    return d

def bs(arr, x):
    lo = 0
    hi = len(arr) - 1
    
    while lo <= hi:
        mid = (lo + hi) // 2
        if arr[mid] == x:
            return True
        elif arr[mid] < x:
            lo = mid + 1
        else:
            hi = mid - 1
    
    return False

n, m, q = rvar()

a = rlist()
b = rlist()
A = sum(a)
B = sum(b)

lA = sorted(A - x for x in a)
lB = sorted(B - x for x in b)

for _ in range(q):
    x = rint()
    d = divisores(x)
    ok = False

    for dd in d:
        if bs(lA, dd):
            aux = x // dd
            if bs(lB, aux):
                ok = True
                break

    print("YES" if ok else "NO")
