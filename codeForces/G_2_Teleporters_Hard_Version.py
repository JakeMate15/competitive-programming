import sys

input = sys.stdin.readline
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n, c = rvar()
    a = rlist()

    for i in range(n):
        a[i] += 1 if i == 0 else min(i + 1, n - i)

    a = [a[0]] + sorted(a[1:])
    
    res = 0
    for val in a:
        if c >= val:
            res += 1
            c -= val
        else:
            break
    print(res)

for _ in range(rint()):
    solve()
