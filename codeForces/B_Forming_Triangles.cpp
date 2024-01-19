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
    map<int, int> rep;
    ll res = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        rep[a[i]]++;
    }

    vector<int> aux;
    for(auto [v, r]: rep) {
        res += (r >= 3 ? );
        aux.push_back(v);
    }

    for(int i = 2; i < sz(aux); i++) {
        res += (aux[i - 1] + aux[i - 2] != aux[i]);
    }

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