import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n = rint()
    arr = rlist()

    ok = True
    for i in range(n - 1):
        if abs(arr[i] - arr[i + 1]) == 5 or abs(arr[i] - arr[i + 1]) == 7:
           pass
        else:
            ok = False
    if ok:
        print("YES")
    else:
        print("NO")
           
    

for _ in range(rint()):
    solve()