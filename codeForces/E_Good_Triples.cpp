#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

vector<ll> veces(30);

void precal() {
    int i = 9;
    for(int j = 0; j <= i; j++) {
        for(int k = 0; k <= i; k++) {
            for(int l = 0; l <= i; l++) {
                veces[j + k + l]++;
            }
        }
    }
}

void sol(){
    string s;
    cin >> s;

    ll res = 1;

    for(auto x: s) {
        ll dig = x - '0';
        res *= veces[dig];
    }

    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    precal();

    while(t--){
        sol();
    }

    return 0;
}