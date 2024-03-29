#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

ll gauss(ll n) {
    if(n <= 0) return 0;
    return (n * (n + 1)) / 2;
}

void sol(){
    int n, mn, temp;
    cin >> n >> mn >> temp;

    vector<int> a(n), curr;
    vector<vector<int>> aux;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] <= temp) {
            curr.push_back(a[i]);
        }
        else {
            aux.push_back(curr);
            curr = vector<int>();
        }
    }
    aux.push_back(curr);
    
    ll res = 0;
    for(auto x: aux) {
        if(sz(x) >= mn) {
            res += gauss(sz(x) - mn + 1);
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