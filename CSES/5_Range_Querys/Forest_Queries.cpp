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

    vector<vector<ll>> a(n + 1, vector<ll>(n + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char x;
            cin >> x;
            a[i][j] = (x == '*');
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }

    while(q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        ll res = a[y2][x2] - (a[y2][x1 - 1] + a[y1 - 1][x2]) + a[y1 - 1][x1 - 1];
        cout << res << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}