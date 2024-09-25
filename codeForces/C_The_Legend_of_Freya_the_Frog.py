import sys, math

input = lambda: sys.stdin.readline()[:-1]
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    x, y, k = rvar()
    
    X = math.ceil(x / k)
    Y = math.ceil(y / k)

    print(max(Y * 2, X * 2 - 1))
    

for _ in range(rint()):
    solve()