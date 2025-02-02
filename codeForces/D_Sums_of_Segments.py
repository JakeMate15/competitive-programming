import sys

input = lambda: sys.stdin.readline().strip()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def get_total(l, r, prefix_sums):
    if l > r:
        return 0
    return prefix_sums[r] - prefix_sums[l - 1]

def get_total_sums(l, r, prefix_sums_sums):
    if l > r:
        return 0
    return prefix_sums_sums[r] - prefix_sums_sums[l - 1]

def solve():
    n = rint()
    a = [0] + rlist()
    prefix_sums = [0] * (n + 1)
    prefix_sums_sums = [0] * (n + 1)
    counts = [0] * (n + 1)
    prefix_counts = [0] * (n + 1)

    for i in range(1, n + 1):
        prefix_sums[i] = prefix_sums[i - 1] + a[i]
        prefix_sums_sums[i] = prefix_sums_sums[i - 1] + prefix_sums[i]
        counts[i] = n - i + 1
        prefix_counts[i] = prefix_counts[i - 1] + counts[i]

    q = rint()
    for _ in range(q):
        l_i, r_i = rvar()
        total = 0

        l_low, l_high, l_start = 1, n, n + 1
        while l_low <= l_high:
            l_mid = (l_low + l_high) // 2
            if prefix_counts[l_mid] >= l_i:
                l_start = l_mid
                l_high = l_mid - 1
            else:
                l_low = l_mid + 1

        l_low, l_high, l_end = 1, n, 0
        while l_low <= l_high:
            l_mid = (l_low + l_high) // 2
            if prefix_counts[l_mid - 1] <= r_i:
                l_end = l_mid
                l_low = l_mid + 1
            else:
                l_high = l_mid - 1

        if l_start > l_end:
            print(0)
            continue

        for l in range(l_start, l_end + 1):
            pos_l_start = prefix_counts[l - 1] + 1
            pos_l_end = prefix_counts[l]
            overlap_start = max(l_i, pos_l_start)
            overlap_end = min(r_i, pos_l_end)
            num_overlaps = overlap_end - overlap_start + 1
            if num_overlaps <= 0:
                continue

            k_start = overlap_start - pos_l_start + 1
            k_end = overlap_end - pos_l_start + 1

            r_start = l + k_start - 1
            r_end = l + k_end - 1

            sum_prefix_sums_r = get_total_sums(r_start, r_end, prefix_sums_sums)
            total += sum_prefix_sums_r - num_overlaps * prefix_sums[l - 1]
        
        print(total)

for _ in range(1):
    solve()
