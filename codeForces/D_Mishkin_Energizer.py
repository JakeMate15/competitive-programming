import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()
    cntL = s.count('L')
    cntI = s.count('I')
    cntT = s.count('T')
    if n == 1 or len(set(s)) == 1:
        sys.stdout.write("-1\n")
        continue
    sol = False
    lb = max(max(cntL, cntI), cntT, (n + 2) // 3)
    for k in range(lb, n + 1):
        m = 3 * k - n
        need = [k - cntL, k - cntI, k - cntT]
        cur = list(s)
        ops = []
        possible = True
        for op in range(m):
            found = False
            for i in range(len(cur) - 1):
                if cur[i] == cur[i + 1]:
                    continue
                a = cur[i]
                b = cur[i + 1]
                if (a == 'L' and b == 'I') or (a == 'I' and b == 'L'):
                    ins = 'T'
                elif (a == 'L' and b == 'T') or (a == 'T' and b == 'L'):
                    ins = 'I'
                else:
                    ins = 'L'
                idx = 0 if ins == 'L' else (1 if ins == 'I' else 2)
                if need[idx] > 0:
                    ops.append(i + 1)
                    cur.insert(i + 1, ins)
                    need[idx] -= 1
                    found = True
                    break
            if not found:
                possible = False
                break
        if possible and need[0] == 0 and need[1] == 0 and need[2] == 0:
            sys.stdout.write(str(len(ops)) + "\n")
            for x in ops:
                sys.stdout.write(str(x) + "\n")
            sol = True
            break
    if not sol:
        sys.stdout.write("-1\n")