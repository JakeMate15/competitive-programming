import sys
input = sys.stdin.read

def dfs(nodo, padre, h):
    hoja = True
    tM = True
    tB = True

    for u in g[nodo]:
        if padre == u:
            continue

        hoja = False
        dfs(u, nodo, h + 1)

        if not hoja:
            tM &= not win[u]
            tB &= win[u]

    win[nodo] = (hoja and (h % 2 == 0))

    if not hoja:
        if (h & 1 and not tM) or (h % 2 == 0 and tB):
            win[nodo] = True


data = input().split()
index = 0

n = int(data[index])
index += 1
t = int(data[index])
index += 1

g = [[] for _ in range(n + 1)]
win = [0] * (n + 1)

for _ in range(n - 1):
    u = int(data[index])
    index += 1
    v = int(data[index])
    index += 1
    g[u].append(v)
    g[v].append(u)

raiz = int(data[index])

dfs(raiz, 0, 0)
print("Hermione" if win[raiz] else "Ron")
