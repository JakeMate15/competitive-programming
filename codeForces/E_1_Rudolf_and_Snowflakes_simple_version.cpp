#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

set<ll> pots;

void sol(){
    ll n;
    cin >> n;
    cout << (pots.count(n) && n >= 7LL ? "YES" : "NO") << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    for(int i = 2; i <= 1e3; i++) {
        ll sum = 1 + i, pot = i * i;
        while(pot <= 1e6) {
            sum += pot;
            pots.insert(sum);
            pot *= i;
        }
    }

    while(t--){
        sol();
    }

    return 0;
}