import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n, a, b = rvar()
    g = math.gcd(a, b)
    arr = [i % g for i in rlist()]

    arr.sort()
    
    ans = arr[n - 1] - arr[0]
    for i in range(n - 1):
        ans = min(ans, arr[i] + g - arr[i + 1])

    print(ans)


for _ in range(rint()):
    solve()