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
    int n, nn;
    cin >> n;

    vector<int> res(n);
    iota(all(res), 1);
    reverse(all(res));
    
    for(int i = 1; i <= n; i++) {
        rotate(res.rbegin(), res.rbegin() + i, res.rend(l));
        for(int j = 0; j < n; j++) {
            cout << res[j] << " \n"[j == n - 1];
        }
    }
    
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