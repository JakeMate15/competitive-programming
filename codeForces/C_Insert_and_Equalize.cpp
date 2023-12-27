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

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a));

    int g = 0;
    for(int i = 0; i < n; i++) {
        g = gcd(g, a[n - 1] - a[i]);
        // cerr << a[i] << " \n"[i == n - 1];
    }

    ll res = 0;
    for(int i = 0; i < n; i++) {
        res += (a[n - 1] - a[i]) / (g == 0 ? 1 : g);
    }

    int mx = INT_MAX;
    for(int i = n - 1; i >= 1; i--) {
        if(a[i] - a[i - 1] > g) {
            mx = a[i] - g;
            break;
        }
    }

    if(mx == INT_MAX) {
        res += n;
    }
    else {
        res = res + (a[n - 1] - mx) / g;
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