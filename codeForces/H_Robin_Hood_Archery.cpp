#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void sol () {
    ll impares = 0;
    vector<ll> mp, a;

    auto add = [&] (ll idx, ll end) ->  void {
        mp[a[idx]]++;
        if (mp[a[idx]] & 1) {
            impares--;
        } else {
            impares++;
        }
    };

    auto del = [&] (ll idx, ll end) -> void {
        mp[a[idx]]--;
        if (mp[a[idx]] & 1) {
            impares++;
        } else {
            impares--;
        }
    };

    auto calc = [&] () -> ll {
        return impares == 0;
    };

    auto mosAlgo = [&] (vector<pair<int, int>> Q, ll n, ll q) -> vector<int> {
        ll L = 0, R = 0, blk = 350;
        vector<int> s(Q.size()), res = s;

        #define K(x) pair<int, int> (x.first / blk, x.second ^ -(x.first / blk & 1))

        iota(s.begin(), s.end(), 0);
        sort(s.begin(), s.end(), [&](ll s, ll t) { 
            return K(Q[s]) < K(Q[t]); 
        });

        for (ll qi : s) {
            pair<int, int> q = Q[qi];
            while (L > q.first) add(--L, 0);
            while (R < q.second) add(R++, 1);
            while (L < q.first) del(L++, 0);
            while (R > q.second) del(--R, 1);
            res[qi] = calc();
        }
        return res;
    };

    a.clear();

    impares = 0;
    ll n, q;
    cin >> n >> q;
    a.resize(n);

    ll mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    mp.assign(mx + 5, 0);
    vector<pair<int, int>> Q(q);
    for (int i = 0; i < q; i++) {
        cin >> Q[i].first >> Q[i].second;
        Q[i].first--;
    }

    auto ans = mosAlgo(Q, n, q);
    for (int i = 0; i < q; i++) { 
        cout << (ans[i] ? "YES" : "NO") << "\n"; 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        sol();
    }
}