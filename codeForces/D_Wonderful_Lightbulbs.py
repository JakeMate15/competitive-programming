import sys

data = sys.stdin.read().split()
it = iter(data)
T = int(next(it))
for _ in range(T):
    n = int(next(it))
    sx = 0
    sd = 0
    for _ in range(n):
        x = int(next(it))
        y = int(next(it))
        sx ^= x
        sd ^= x + y
    s = sx
    t = sd - sx
    print(s, t)