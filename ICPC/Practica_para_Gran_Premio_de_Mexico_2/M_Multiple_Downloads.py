import sys
input = sys.stdin.read
d = input().split()

n = int(d[0])
t = int(d[1])

s = [0.0, 0.0]
i = 2
for _ in range(n):
    c = d[i]
    x = float(d[i + 1])
    s[0 if c == 'P' else 1] += x
    i += 2

mn = [s[0] / (0.25 * t), s[1] / (0.75 * t)]
res = 0.0
eps = 1e-9

if mn[0] + eps < mn[1]:
    xd = s[1] - (0.75 * t * mn[0])
    res = ((xd / t) + mn[0])
else:
    xd = s[0] - (0.25 * t * mn[1])
    res = ((xd / t) + mn[1])

print(f"{res:.10f}")