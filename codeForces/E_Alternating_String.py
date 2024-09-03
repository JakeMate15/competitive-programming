from collections import Counter
import sys
input = sys.stdin.read

def get(s: str, n: int) -> int:
    if n % 2 == 1:
        return min(get(s[:-1], n - 1) + 1,
                   get(s[1:], n - 1) + 1)
    
    pares = Counter(s[i] for i in range(0, n, 2))
    imp = Counter(s[i] for i in range(1, n, 2))
    
    mxPa, Parmax = max(pares.items(), key=lambda x: x[1], default=(None, 0))
    mxImp, Impmax = max(imp.items(), key=lambda x: x[1], default=(None, 0))
    
    res = n // 2 - Parmax + n // 2 - Impmax
    
    if mxPa == mxImp:
        segPar = max((count for char, count in pares.items() if char != mxPa), default=0)
        segImp = max((count for char, count in imp.items() if char != mxImp), default=0)
        
        res = min(res, n // 2 - segPar + n // 2 - Impmax)
        res = min(res, n // 2 - Parmax + n // 2 - segImp)
    
    return res

data = input().split()

t = int(data[0])
index = 1
resss = []

for _ in range(t):
    n = int(data[index])
    s = data[index + 1]
    index += 2
    resss.append(get(s, n))

for res in resss:
    print(res)
