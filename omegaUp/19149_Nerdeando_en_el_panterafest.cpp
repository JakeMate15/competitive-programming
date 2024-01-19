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

    map<pair<int, int>, int> st;
    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;

        for(int j = 0; j < m; j++) {
            int u, v;
            cin >> u;
            v = i;  

            if(u > v) {
                swap(u, v);
            }

            st[{u, v}]++;
        }
    }

    int res = 0;
    for(auto [p, r]: st) {
        res += r >= 2;
    }
    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}