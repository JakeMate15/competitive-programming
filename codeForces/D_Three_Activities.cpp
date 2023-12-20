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

    vector<vector<pair<ll, int>>> a(3, vector<pair<ll, int>>(n));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j].first;
            a[i][j].second = j;
        }
        sort(a[i].rbegin(), a[i].rend());
    }

    ll res = 0;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) { 
            for(int k = 0; k < 3; k++) {
                if(a[0][i].second == a[1][j].second || a[0][i].second == a[2][k].second || a[1][j].second == a[2][k].second) {
                    continue;
                }

                ll curr = a[0][i].first + a[1][j].first + a[2][k].first;
                res = max(res, curr);
            }
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