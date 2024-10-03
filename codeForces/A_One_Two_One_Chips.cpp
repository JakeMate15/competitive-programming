#include<bits/stdc++.h>
using namespace std;

typedef long double ld;

struct pto {
    ld x, y, z;
};

struct cubo {
    ld x, y, z, d;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pto> ptos(n);
    for (int i = 0; i < n; ++i) {
        ld x, y, z;
        cin >> x >> y >> z;
        ptos[i] = {x, y, z};
    }

    vector<cubo> cubos(m);
    for (int i = 0; i < m; ++i) {
        ld x, y, z, d;
        cin >> x >> y >> z >> d;
        cubos[i] = {x, y, z, d};
    }

    vector<ld> esperanza(n, 0.0L);

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_real_distribution<ld> dist(0.0L, 1.0L);

    const int samples_per_cube = 50000000;
    auto start_time = chrono::steady_clock::now();

    for (const cubo& cube : cubos) {
        vector<int> cnt_closest(n, 0);
        vector<int> cnt_second_closest(n, 0);
        vector<int> cnt_farthest(n, 0);
        vector<int> cnt_second_farthest(n, 0);

        int actual_samples = 0;

        for (int sample = 0; sample < samples_per_cube; ++sample) {
            ld rx = dist(rng);
            ld ry = dist(rng);
            ld rz = dist(rng);
            pto sp = {
                cube.x + rx * cube.d,
                cube.y + ry * cube.d,
                cube.z + rz * cube.d
            };

            vector<pair<ld, int>> dists(n);
            for (int i = 0; i < n; ++i) {
                ld dx = sp.x - ptos[i].x;
                ld dy = sp.y - ptos[i].y;
                ld dz = sp.z - ptos[i].z;
                ld dist_sq = dx * dx + dy * dy + dz * dz;
                dists[i] = { dist_sq, i };
            }

            // Find indices for closest, second closest, farthest, second farthest
            nth_element(dists.begin(), dists.begin(), dists.end());
            int idx_closest = dists[0].second;

            nth_element(dists.begin() + 1, dists.begin() + 1, dists.end());
            int idx_second_closest = dists[1].second;

            nth_element(dists.begin(), dists.end() - 1, dists.end());
            int idx_farthest = (dists.end() - 1)->second;

            nth_element(dists.begin(), dists.end() - 2, dists.end());
            int idx_second_farthest = (dists.end() - 2)->second;

            cnt_closest[idx_closest]++;
            cnt_second_closest[idx_second_closest]++;
            cnt_farthest[idx_farthest]++;
            cnt_second_farthest[idx_second_farthest]++;

            actual_samples = sample + 1;

            // Check if we're close to the time limit
            if (sample % 1000000 == 0) {
                auto current_time = chrono::steady_clock::now();
                auto elapsed = chrono::duration_cast<chrono::seconds>(current_time - start_time).count();
                if (elapsed >= 6) {
                    // Time is almost up, break the loop
                    break;
                }
            }
        }

        // Update expected values
        for (int i = 0; i < n; ++i) {
            ld e = (cnt_closest[i] * 1.0L + cnt_second_closest[i] * 2.0L
                            - cnt_farthest[i] * 1.0L - cnt_second_farthest[i] * 2.0L)
                            / actual_samples;
            esperanza[i] += e;
        }
    }

    cout << fixed << setprecision(10);
    for (int i = 0; i < n; ++i) {
        cout << esperanza[i] << '\n';
    }

    return 0;
}
