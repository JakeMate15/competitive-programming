import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n, q = rvar()

    arr = rlist()
    arr += arr

    for i in range(1, 2 * n):
        arr[i] += arr[i - 1]

    query = lambda l, r: arr[r] if l <= 0 else arr[r] - arr[l - 1]

    for i in range(q):
        l, r = rvar()
        l -= 1
        r -= 1

        p1, p2 = l // n, r // n
        sep = p2 - p1 - 1

        p1 %= n
        p2 %= n
        l %= n
        r %= n

        res = 0
        if p1 == p2:
            res += query(l + p1, r + p1)
        else:
            res += arr[n - 1] * sep
            res += query(p2, p2 + r)
            res += query(p1 + l, p1 + n - 1)

        print(res)
    

for _ in range(rint()):
    solve()