#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

/*
4 -> 10
5 -> 12
6 -> 14

1 1
2 3
3 6
4 10
5 15
6 21

*/

ll g(ll n) {
    return (n * (n + 1)) / 2;
}

void sol(){
    ll n;
    cin >> n;

    ll res = n * 4 + g(n - 1) + g(n - 2) + 1;
    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}