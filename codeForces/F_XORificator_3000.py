import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def get(n):
    if n < 0:
        return 0
    if n % 4 == 0:
        return n
    elif n % 4 == 1:
        return 1
    elif n % 4 == 2:
        return n + 1
    else:
        return 0

def solve():
    l, r, i, k = rvar()
    s = 1 << i
    total_XOR = get(r) ^ get(l - 1)
    t_min = (l - k + s - 1) // s
    t_min = max(0, t_min)
    t_max = (r - k) // s
    if t_max < t_min:
        print(total_XOR)
        return
    n = t_max - t_min + 1
    low_bits_k = k % s
    c = k >> i
    XOR_t = get(t_max) ^ get(t_min - 1)
    if n % 2 == 1:
        XOR_over_xi = low_bits_k ^ (c << i) ^ (XOR_t << i)
    else:
        XOR_over_xi = XOR_t << i
    answer = total_XOR ^ XOR_over_xi
    print(answer)

for _ in range(rint()):
    solve()
