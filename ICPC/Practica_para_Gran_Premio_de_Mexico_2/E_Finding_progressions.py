import sys

def g(n, st, fn):
    if fn > R:
        return s + 1
    return (n * (st + fn)) // 2

def ok(st, d):
    if d == 0:
        return st == s and st == a
    l, r = 2, 200000
    while l <= r:
        mid = (l + r) // 2
        sum = g(mid, st, st + (mid - 1) * d)
        if sum == s:
            return st + (mid - 1) * d >= a
        elif sum > s:
            r = mid - 1
        else:
            l = mid + 1
    return False

global a, s, L, R
a, s, L, R = map(int, input().split())
cnt = 0
if a == s:
    print(1)
    sys.exit()
for i in range(L, a):
    x = a - i
    for j in range(1, int(x ** 0.5) + 1):
        if x % j == 0:
            cnt += ok(i, j)
            if j * j != x:
                cnt += ok(i, x // j)
for i in range(R - a + 1):
    cnt += ok(a, i)
print(cnt)
