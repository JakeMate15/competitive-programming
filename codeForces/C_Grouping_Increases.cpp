#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

int lis_with_path(const vector<int>& a, vector<int>& path) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n + 1, INF), p(n, -1), id(n + 1, -1);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[l - 1] < a[i] && a[i] < d[l]) {
            d[l] = a[i];
            id[l] = i;
            p[i] = (l > 1) ? id[l - 1] : -1;
        }
    }

    int ans = 0, idx = 0;
    for (int l = 0; l <= n; l++) {
        if (d[l] < INF) {
            ans = l;
            idx = id[l];
        }
    }

    path.clear();
    while (idx != -1) {
        path.push_back(idx);
        idx = p[idx];
    }
    reverse(path.begin(), path.end());

    return ans;
}


void sol(){
    // cerr << "============\n";
    int n;
    cin >> n;

    vector<int> a(n);
    set<int> idx;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        idx.insert(i);
    }
    reverse(all(a));

    vector<int> l(n);
    auto lis = lis_with_path(a, l);
    // cerr << lis << "\n";
    // if(lis == n) {
    //     cout << 0 << "\n";
    //     return;
    // }
    
    // for(auto x: l) {
    //     cerr << x << " ";
    // }
    // cerr << "\n";

    vector<int> nc;
    for(auto x: l) {
        idx.erase(x);
    }
    for(auto x: idx) {
        nc.push_back(a[x]);
    }

    reverse(all(nc));
    int res = 0;
    for(int i = 0; i < sz(nc) - 1; i++) {
        res += (nc[i] < nc[i + 1]);
    }

    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}