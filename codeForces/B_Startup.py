import sys
input = lambda: sys.stdin.readline().strip()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n, k = rvar()
    tot = {}

    for _ in range(k):
        b_i, c_i = rvar()
        if b_i in tot:
            tot[b_i] += c_i
        else:
            tot[b_i] = c_i

    total_costs = list(tot.values())
    total_costs.sort(reverse=True)

    bS = min(n, len(total_costs))
    ans = sum(total_costs[:bS])

    print(ans)

for _ in range(rint()):
    solve()
