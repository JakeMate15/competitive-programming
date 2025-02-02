#include <bits/stdc++.h>
using namespace std;

struct Hurdle {
    long long l, r;
};

struct PowerUp {
    long long x, v;
};

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        long long L;
        cin >> n >> m >> L;
        vector<Hurdle> hurdles(n);
        for (int i = 0; i < n; ++i) {
            cin >> hurdles[i].l >> hurdles[i].r;
        }
        vector<PowerUp> powerups(m);
        for (int i = 0; i < m; ++i) {
            cin >> powerups[i].x >> powerups[i].v;
        }

        // Map position to list of power-ups at that position
        map<long long, vector<long long>> powerups_at_pos;
        for (int i = 0; i < m; ++i) {
            powerups_at_pos[powerups[i].x].push_back(powerups[i].v);
        }

        // Sort power-ups at each position in decreasing order
        for (auto &entry : powerups_at_pos) {
            sort(entry.second.rbegin(), entry.second.rend());
        }

        // Initialize variables
        long long x = 1;
        long long k = 1;
        int collected_powerups = 0;
        int idx = 0; // index for hurdles

        bool possible = true;

        while (x < L) {
            long long max_reach = x + k;
            long long required_k = 0;
            int temp_idx = idx;

            // Find the maximum required_k among hurdles within current reach
            while (temp_idx < n && hurdles[temp_idx].l <= max_reach) {
                if (x >= hurdles[temp_idx].r + 1) {
                    // Already passed this hurdle
                    temp_idx++;
                    continue;
                } else {
                    required_k = max(required_k, hurdles[temp_idx].r + 1 - x);
                    temp_idx++;
                }
            }

            if (required_k == 0) {
                // No hurdles blocking us
                x = min(max_reach, L);
            } else {
                if (k >= required_k) {
                    // Can proceed
                    x = min(max_reach, L);
                } else {
                    // Need to collect power-ups to increase k
                    long long delta_k = required_k - k;
                    if (powerups_at_pos.count(x) == 0) {
                        // No power-ups at current position
                        possible = false;
                        break;
                    } else {
                        // Collect minimal number of power-ups to cover delta_k
                        vector<long long> &v_list = powerups_at_pos[x];
                        long long sum_v = 0;
                        int count = 0;
                        for (long long v : v_list) {
                            sum_v += v;
                            count++;
                            if (sum_v >= delta_k) {
                                break;
                            }
                        }
                        if (sum_v < delta_k) {
                            // Not enough power-ups
                            possible = false;
                            break;
                        } else {
                            // Update k and collected_powerups
                            k += sum_v;
                            collected_powerups += count;
                            // Remove used power-ups
                            v_list.erase(v_list.begin(), v_list.begin() + count);
                            // Proceed to next iteration
                            continue;
                        }
                    }
                }
            }

            // Update idx
            while (idx < n && hurdles[idx].r + 1 <= x) {
                idx++;
            }
        }

        if (possible) {
            cout << collected_powerups << '\n';
        } else {
            cout << "-1\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
