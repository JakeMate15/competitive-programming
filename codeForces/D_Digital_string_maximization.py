import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    s = list(input().strip())
    n = len(s)
    for i in range(n):
        mx = int(s[i])
        p = i
        for j in range(i + 1, min(i + 10, n)):
            curr = int(s[j]) - (j - i)
            if curr > mx:
                mx = curr
                p = j
        if p != i:
            s[p] = str(mx)
            char = s.pop(p)
            s.insert(i, char)
    print(''.join(s))

for _ in range(rint()):
    solve()
