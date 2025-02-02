import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n = rint()
    arr = rlist()

    cnt = 0
    for i in range(1, n - 1):
        if arr[i] > arr[i - 1] and arr[i] > arr[i + 1]:
            cnt += 1
            if i + 2 < n:
                arr[i + 1] = max(arr[i], arr[i + 2])
            else:
                arr[i + 1] = arr[i]
            
    
    print(cnt)
    print(*arr)
    

for _ in range(rint()):
    solve()