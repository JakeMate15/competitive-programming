import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def query(a, b):
    print("?", a, b)
    sys.stdout.flush()
    response = int(sys.stdin.readline())
    return response

def solve():
    n = rint()
    parent = [-1] * n
    
    children = []
    for i in range(1, n):
        if query(1, i + 1) == 1:
            children.append(i)
    
    if len(children) >= 2:
        parent[children[0]] = 0
        parent[children[1]] = 0
    elif len(children) == 1:
        parent[children[0]] = 0
    
    for i in range(2, len(children)):
        l, r = 0, i - 1
        while l < r:
            mid = (l + r) // 2
            if query(children[mid] + 1, children[i] + 1) == 1:
                r = mid
            else:
                l = mid + 1
        parent[children[i]] = children[l]
    
    for i in range(1, n):
        if parent[i] == -1:
            parent[i] = 0
    
    output = [str(parent[i] + 1) for i in range(1, n)]
    print("!", " ".join(output))
    sys.stdout.flush()

for _ in range(rint()):
    solve()
