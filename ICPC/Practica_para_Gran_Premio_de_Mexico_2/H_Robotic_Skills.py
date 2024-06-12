import sys

input = sys.stdin.read
d = input().split()

n = int(d[0])
a = []
idx = 1
for i in range(n):
    r = []
    for j in range(n):
        r.append(int(d[idx]))
        idx += 1
    a.append(r)

pos = [(i, j) for i in range(n) for j in range(n)]

pos.sort(key=lambda x: a[x[0]][x[1]])

x = [0] * (n * n)
y = [0] * (n * n)
res = 0

for i, j in pos:
    antX = x[i]
    antY = y[j]

    y[j] = max(y[j], antX + 1)
    x[i] = max(x[i], antY + 1)

    # print(f"({i}, {j}) -> {x[i]}")

    res = max(res, x[i], y[j])

print(res)