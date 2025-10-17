#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void sol () {
    int n, m;
    cin >> n >> m;

    vector<int> X(n), R(n);
    for (auto &x: X) {
        cin >> x;
    }
    for (auto &x: R) {
        cin >> x;
    }

    gp_hash_table<int, int, custom_hash> cnt;
    for (int i = 0; i < n; i++) {
        for (int xi = X[i] - R[i]; xi <= X[i] + R[i]; xi++) {
            int sq = sqrtl(1LL * R[i] * R[i] - 1LL * (xi - X[i]) * (xi - X[i]));
            cnt[xi] = max(cnt[xi], 2 * sq + 1);
        }
    }

    int64_t ans = 0;
    for (auto &[v, r]: cnt) {
        ans += r;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}