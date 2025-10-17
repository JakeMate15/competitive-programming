#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        unordered_map<long long,int> cnt;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ++cnt[a[i]];
        }
        bool ok = false;
        for (auto &p : cnt) if (p.second >= 4) { ok = true; break; }
        if (!ok) {
            vector<long long> d;
            d.reserve(cnt.size());
            for (auto &p : cnt) d.push_back(p.first);
            sort(d.begin(), d.end());
            int m = d.size();
            for (int i = 0; i < m && !ok; ++i) {
                if (cnt[d[i]] < 2) continue;
                for (int j = i + 1; j < m; ++j) {
                    if (d[j] != d[j - 1] + 1) break;
                    if (cnt[d[j]] >= 2) { ok = true; break; }
                }
            }
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}
