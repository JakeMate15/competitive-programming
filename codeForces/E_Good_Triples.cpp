#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

ll calc[10];

void sol(){
    string n;
    cin >> n;

    ll res = 1;

    for(auto x: n) {
        int dig = x - '0';
        res *= calc[dig];
        // res *= res[x - '0']; 
    }

    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    for(ll i = 0; i <= 9; i++) {
        for(ll j = 0; j <= i; j++) {
            for(ll k = 0; k <= i; k++) {
                for(ll l = 0; l <= i; l++) {
                    if(j + k + l == i) {
                        calc[i]++;
                    }
                }
            }
        }
    }

    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}