import sys
input = lambda: sys.stdin.readline().strip()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    s = list(input().strip())
    n = len(s)
    count = sum(1 for i in range(n - 3) if s[i:i + 4] == ['1', '1', '0', '0'])

    for _ in range(rint()):
        idx, val = rvar()
        idx -= 1

        if s[idx] == str(val):
            print("YES" if count > 0 else "NO")
            continue

        for j in range(idx - 3, idx + 1):
            if 0 <= j <= n - 4 and s[j:j + 4] == ['1', '1', '0', '0']:
                count -= 1

        s[idx] = str(val)

        for j in range(idx - 3, idx + 1):
            if 0 <= j <= n - 4 and s[j:j + 4] == ['1', '1', '0', '0']:
                count += 1

        print("YES" if count > 0 else "NO")

for _ in range(rint()):
    solve()
