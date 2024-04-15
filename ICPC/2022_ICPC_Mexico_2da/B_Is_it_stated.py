def f(s, clave="it"):
    i = 0
    for c in s:
        if c == clave[i]:
            i += 1
            if i >= len(clave):
                return True
    return False

t = int(input().strip())

for _ in range(t):
    s = input().strip()
    if f(s):
        print("YES")
    else:
        print("NO")
