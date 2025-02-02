#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<ll> a, prefix_sums, prefix_sums_sums, counts, prefix_counts;

ll get_total(int l, int r) {
    if (l > r) return 0;
    return prefix_sums[r] - prefix_sums[l - 1];
}

ll get_total_sums(int l, int r) {
    if (l > r) return 0;
    return prefix_sums_sums[r] - prefix_sums_sums[l - 1];
}

int main() {
    int n;
    scanf("%d", &n);
    a.resize(n + 1);
    prefix_sums.resize(n + 1);
    prefix_sums_sums.resize(n + 1);
    counts.resize(n + 1);
    prefix_counts.resize(n + 1);

    prefix_sums[0] = 0;
    prefix_sums_sums[0] = 0;
    prefix_counts[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        prefix_sums[i] = prefix_sums[i - 1] + a[i];
        prefix_sums_sums[i] = prefix_sums_sums[i - 1] + prefix_sums[i];
        counts[i] = n - i + 1;
        prefix_counts[i] = prefix_counts[i - 1] + counts[i];
    }

    int q;
    scanf("%d", &q);
    while (q--) {
        ll l_i, r_i;
        scanf("%lld %lld", &l_i, &r_i);

        ll total = 0;

        // Binary search to find starting index l_start where the positions in b start overlapping with l_i
        int l_low = 1, l_high = n, l_start = n + 1;
        while (l_low <= l_high) {
            int l_mid = (l_low + l_high) / 2;
            if (prefix_counts[l_mid] >= l_i) {
                l_start = l_mid;
                l_high = l_mid - 1;
            } else {
                l_low = l_mid + 1;
            }
        }

        // Binary search to find ending index l_end where the positions in b end overlapping with r_i
        l_low = 1; l_high = n; int l_end = 0;
        while (l_low <= l_high) {
            int l_mid = (l_low + l_high) / 2;
            if (prefix_counts[l_mid - 1] <= r_i) {
                l_end = l_mid;
                l_low = l_mid + 1;
            } else {
                l_high = l_mid - 1;
            }
        }

        if (l_start > l_end) {
            printf("0\n");
            continue;
        }

        for (int l = l_start; l <= l_end; ++l) {
            ll pos_l_start = prefix_counts[l - 1] + 1;
            ll pos_l_end = prefix_counts[l];
            ll overlap_start = max(l_i, pos_l_start);
            ll overlap_end = min(r_i, pos_l_end);
            ll num_overlaps = overlap_end - overlap_start + 1;
            if (num_overlaps <= 0) continue;

            ll k_start = overlap_start - pos_l_start + 1;
            ll k_end = overlap_end - pos_l_start + 1;

            ll r_start = l + k_start - 1;
            ll r_end = l + k_end - 1;

            ll sum_prefix_sums_r = get_total_sums(r_start, r_end);
            total += sum_prefix_sums_r - num_overlaps * prefix_sums[l - 1];
        }
        printf("%lld\n", total);
    }
    return 0;
}
