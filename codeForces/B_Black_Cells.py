import sys
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def is_feasible(a, k):
    n = len(a)
    extra_cells_painted = 0
    i = 0
    while i < n:
        if i + 1 < n and a[i + 1] - a[i] <= k:
            i += 2
        else:
            left = a[i] - k
            right = a[i] + k
            total_positions = right - left + 1
            num_required_in_range = bisect_right(a, right) - bisect_left(a, left)
            if num_required_in_range < total_positions:
                extra_cells_painted += 1
                if extra_cells_painted > 1:
                    return False
                i += 1
            else:
                return False
    return True

def solve():
    n = rint()
    a = rlist()
    a.sort()
    left, right, ans = 0, int(1e18), -1
    while left <= right:
        mid = left + (right - left) // 2
        if is_feasible(a, mid):
            ans = mid
            right = mid - 1
        else:
            left = mid + 1
    print(ans)

for _ in range(rint()):
    solve()
