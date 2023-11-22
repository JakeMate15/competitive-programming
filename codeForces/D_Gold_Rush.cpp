#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

bool f(ll n, ll m) {
    if(n == m) 
        return true;

    if(n < m)
        return false;
    ll a = (n * 2) / 3;
    ll b = n / 3;

    if(a + b != n)
        return false;

    if(a == m || b == m)
        return true;

    return f(a, m) | f(b, m);
}

void sol(){
    ll n, m;
    cin >> n >> m;

    cout << (f(n, m) ? "YES" : "NO") << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    cin>>t;

    while(t--){
        sol();
    }

    return 0;
}