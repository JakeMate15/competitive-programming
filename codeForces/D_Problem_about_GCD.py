import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    L, R, G = rvar()
 
    if L % G != 0:
        L += G - L % G
 
    if R % G != 0:
        R -= R % G
 
    A, B = -1, -2
    iters = 0;
    a = L
    while a <= R and iters < 100:
        b = R
        while b - a > B - A:
            if math.gcd(a, b) == G:
                A = a
                B = b
                break
            b -= G
        a += G
        iters += 1

    print(A, max(A, B))

for _ in range(rint()):
    solve()