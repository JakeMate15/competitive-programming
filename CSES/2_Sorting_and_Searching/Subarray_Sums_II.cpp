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
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, x;
    cin >> n >> k;

    gp_hash_table<long long, int, custom_hash> mp;
    long long sum = 0, res = 0;
    for (int i = 0; i < n; i++) {
        mp[sum]++;

        cin >> x;
        sum += x;

        if (mp.find(sum - k) != mp.end()) {
            res += mp[sum - k];
        }
    }

    cout << res << "\n";
    return 0;
}