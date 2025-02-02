import sys, math
from collections import deque

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n = rint()
    print(f"xor 1 {n}")
    sys.stdout.flush()
    total_xor = rint()
    positions = []
    q = deque()
    q.append((1, n))
    while q and len(positions) < 2:
        l, r = q.popleft()
        if l == r:
            positions.append(l)
            continue
        mid = (l + r) // 2
        print(f"xor {l} {mid}")
        sys.stdout.flush()
        s = rint()
        if s == -1:
            sys.exit()
        if s == 0:
            q.append((mid + 1, r))
        else:
            q.append((l, mid))
    if len(positions) < 2:
        while q and len(positions) < 2:
            l, r = q.popleft()
            if l == r:
                positions.append(l)
                continue
            mid = (l + r) // 2
            print(f"xor {l} {mid}")
            sys.stdout.flush()
            s = rint()
            if s == -1:
                sys.exit()
            if s == 0:
                q.append((mid + 1, r))
            else:
                q.append((l, mid))
    a = positions[0]
    b = positions[1]
    c = total_xor ^ a ^ b
    print(f"ans {a} {b} {c}")
    sys.stdout.flush()
    verdict = input().strip()
    if verdict != "Correct":
        sys.exit()

for _ in range(rint()):
    solve()
