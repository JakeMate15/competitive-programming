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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(m + 1);
    int fed;
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    cin >> fed;

    int res = 0;
    for(int i = 0; i < m; i++) {
        a[i] ^= fed;
        int dif = 0;
        for(int j = 0; j < n; j++) {
            if((1 << j) & a[i]) {
                dif++;
            }
        }

        res += (dif <= k);
    }
    cout << res << "\n";
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