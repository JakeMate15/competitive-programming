#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol(){
    int n;
    cin >> n;

    vector<ii> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(all(a));

    ll res = 0;

    cerr << "============\n";
    for(int i = 0; i < n; i++) {
        auto it1 = upper_bound(all(a), make_pair(a[i].first, a[i].second));
        // auto it2 = upper_bound(all(a), make_pair(-INT_MAX, a[i].second + 1));

        cerr << (*it1).first << " " << (*it1).second << "\n";
        cerr << (*it2).first << " " << (*it2).second << "\n\n";

        int cnt = it2 - it1;
        res += max(0, cnt);
    }

    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}