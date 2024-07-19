#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(v)          v.begin(), v.end()
#define rall(v)         v.rbegin(), v.rend()
#define sz(a)           (int)a.size()

void sol() {
    int n, k;
    cin >> n >> k;

    vector<int> neg = {0}, pos = {0};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x < 0) {
            neg.push_back(-x);
        }
        else {
            pos.push_back(x);
        }
    }

    sort(rall(pos));
    sort(rall(neg));

    ll aux = max(pos[0], neg[0]);

    ll res = 0;
    for (int i = 0; i < sz(pos); i += k) {
        res += 2LL * pos[i];
    }
    for (int i = 0; i < sz(neg); i += k) {
        res += 2LL * neg[i];
    }

    cout << res - aux << "\n";

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
