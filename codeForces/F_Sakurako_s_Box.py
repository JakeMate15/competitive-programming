import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

mod = 10**9 + 7

def solve():
    n = rint()
    arr = rlist()

    aux = arr.copy()
    arr = [0] + arr + [0]
    for i in range(1, n + 2):
        arr[i] += arr[i - 1]
        arr[i] %= mod

    s = 0
    for i in range(1, n + 1):
        s += (aux[i - 1] * (arr[n + 1] - arr[i])) % mod

    q = pow(n * (n - 1) // 2, mod - 2, mod)

    print((s * q) % mod)
    
for _ in range(rint()):
    solve()