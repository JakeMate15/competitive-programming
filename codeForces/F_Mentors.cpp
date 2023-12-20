#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol(){
    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(all(a));
    
    vector<int> cnt(n + 1), donde(n + 1);
    for(int i = 1; i <= n; i++) {
        cnt[a[i].second] = (lower_bound(all(a), make_pair(a[i].first, -1))) - a.begin();
        donde[a[i].second] = i;
    }

    while(q--) {
        int u, v;
        cin >> u >> v;

        int ui = donde[u], vi = donde[v];
        if(a[ui].first > a[vi].first) {
            cnt[u]--;
        }   
        else if(a[vi].first > a[ui].first) {
            cnt[v]--;
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << max(0, cnt[i] - 1) << " ";
    }
    nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}