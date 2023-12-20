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
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<pair<int, int>> c(n);
    for(int i = 0; i < n; i++) {
        c[i] = {a[i], b[i]};
    }

    sort(all(c), [&](pair<int, int> a, pair<int, int> b) {
        return a.first + a.second > b.first + b.second;
    });

    ll res = 0;
    for(int i = 0; i < n; i++) {
        if(i & 1) {
            res -= c[i].second - 1;
        }
        else {
            res += c[i].first - 1;
        }
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