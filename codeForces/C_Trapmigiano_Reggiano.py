import sys, math
from collections import deque

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n, st, en = rvar()
    adj = [[] for _ in range(n+1)]
    for _ in range(n-1):
        u, v = rvar()
        adj[u].append(v)
        adj[v].append(u)
    if st == en:
        print(" ".join(str(i) for i in range(1, n+1)))
        return
    parent = [-1]*(n+1)
    vis = [False]*(n+1)
    q = deque()
    q.append(st)
    vis[st] = True
    while q:
        cur = q.popleft()
        if cur == en:
            break
        for nx in adj[cur]:
            if not vis[nx]:
                vis[nx] = True
                parent[nx] = cur
                q.append(nx)
    if parent[en] == -1:
        print(-1)
        return
    path = []
    cur = en
    while cur != -1:
        path.append(cur)
        cur = parent[cur]
    path.reverse()
    inPath = [False]*(n+1)
    for v in path:
        inPath[v] = True
    perm = [i for i in range(1, n+1) if not inPath[i]] + path
    if len(perm) != n:
        print(-1)
    else:
        print(" ".join(str(v) for v in perm))

for _ in range(rint()):
    solve()
