import sys

def get(a, b, op):
    if op <= 1:
        mn = min(a, b // 2)
        r1 = get(a - mn, b - mn * 2, op + 1) + mn
        mn = min(a // 3, b)
        r2 = get(a - mn * 3, b - mn, op + 1) + mn
        return max(r1, r2)
    
    return a // 5 + b // 5

input = sys.stdin.read

d = input().strip().split()
n = int(d[0])
a = [0] * 5

for i in range(1, n + 1):
    x = int(d[i])
    a[x % 5] += 1

res = a[0]
mn = min(a[1], a[4])
a[1] -= mn
a[4] -= mn
res += mn

mn = min(a[2], a[3])
a[2] -= mn
a[3] -= mn
res += mn

res += max(
    get(a[2], a[4], 0),
    get(a[1], a[2], 0),
    get(a[3], a[1], 0),
    get(a[4], a[3], 0)
)

print(res)
