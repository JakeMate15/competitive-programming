import sys, math

input = lambda: sys.stdin.readline()[:-1]
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n = rint()
    
    arr = [rlist() for i in range(n)]
    res = []

    vis = [False] * (n + 1)
    for i in range(n - 2, -1, -1):
        aux = {}
        for j in range(n):
            if arr[j][i] in aux:
                aux[arr[j][i]] += 1
            else:
                aux[arr[j][i]] = 1
        
        nums = sorted(aux, key = aux.get, reverse=True)
        for x in nums:
            if vis[x]:
                continue
            vis[x] = True
            res.append(x)


    res = res[::-1]
    print(' '.join(str(i) for i in res))

    
    

for _ in range(rint()):
    solve()