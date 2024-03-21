#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()
#define sz(a)   (int)a.size()
typedef long long ll;

const int mod = 1e9 + 7;

int main () {
    int n; 
    cin >> n;
    vector<tuple<ll, ll, ll>> a(n);
    for (int i = 0; i < n; i++){
        ll tam, p;
        cin >> tam >> p;
        a[i] = {p, tam, i + 1};
    }

    sort(a.rbegin(), a.rend());

    int m; 
    cin >> m;
    set<pair<ll, ll>> mesas;
    for (int i = 0; i < m; i++) {
        ll w; 
        cin >> w;
        mesas.insert({w, i + 1});
    }

    vector<pair<ll, ll>> res;
    ll sum = 0; 
    for (auto [p, tam, i] : a){
        auto it = mesas.lower_bound({tam, 0});
        if (it != mesas.end()){
            res.emplace_back(i, it -> second);
            sum += p;
            mesas.erase(it);
        }
    }
 
    cout << sz(res) << " " << sum << "\n";
    for (auto [a, b]: res) {
        cout << a << " " << b << "\n";
    }

    return 0;
}