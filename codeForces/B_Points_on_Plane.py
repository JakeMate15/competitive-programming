import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())

    lo = -1
    hi = 1000000000
    while (lo + 1 < hi):
        mid = (lo + hi) // 2
        if (mid * mid >= n):
            hi = mid
        else:
            lo = mid
    print(hi - 1)