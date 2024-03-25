import sys
input = sys.stdin.readline
import math

def binpow(a, b):
    res = 1
    while b > 0:
        if b & 1:
            res = res * a
        a = a * a
        b >>= 1
    return res

n = int(input())
if n == 0:
    print(1)
else:
    p = math.ceil(math.log(n, 6))
    ok = binpow(6, int(p))

    while ok > n:
        p -= 1
        ok = binpow(6, p)
    print(p + 1)