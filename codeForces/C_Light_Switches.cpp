#include<bits/stdc++.h>
using namespace std;

#define sz(a)   (int) a.size()
#define all(a)  a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

void sol () {
    int n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    for (auto &x: arr) {
        cin >> x;
    }

    sort(all(arr));

    vector<ii> rang;
    ll mn = arr.back();
    for (int i = 0; i < n - 1; i++) {
        ll lo = -2, hi = INT_MAX;
        while (lo + 1 < hi) {
            ll mid = (lo + hi) / 2;

            ll ini = arr[i] + (2LL * mid) * k;
            ll fin = ini + k - 1;

            if (ini <= arr.back() + k - 1)
                lo = mid;
            else 
                hi = mid;
        }
        
        ll ini = arr[i] + (2LL * lo) * k;
        ll fin = ini + k - 1;

        rang.emplace_back(ini, fin);

        mn = min(mn, ini);
    }
    rang.emplace_back(arr.back(), arr.back() + k - 1);

    vector<int> pref(3 * k + 5);
    for (auto &[l, r]: rang) {
        l -= mn - 1, r -= mn - 1;
        pref[l]++;
        pref[r + 1]--;
    }
 
    for (int i = 1; i < 3 * k + 5; i++) {
        pref[i] += pref[i - 1];
        if (pref[i] == n) {
            cout << i + mn - 1 << "\n";
            return;
        }
    }
 
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);
 
    int t = 1;
    cin >> t;
 
    while(t--) {
        sol();
    }
 
    return 0;
}