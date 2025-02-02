import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n = rint()
    arr = rlist()

    arr.sort()

    if arr[0] != arr[1]:
        print("YES")
        return

    for i in range(1, n):
        if (arr[i] % arr[0] != 0):
            print("YES")
            return
    print("NO")
    
for _ in range(rint()):
    solve()