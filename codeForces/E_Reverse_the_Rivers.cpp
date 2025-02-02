#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

void sol () {
    int n, k, q;
    cin >> n >> k >> q;
    
    vector<vector<int>> a(k, vector<int>());
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < k; ++j){
            int x;
            cin >> x;
            a[j].push_back(x);
        }
    }
    
    vector<vector<int>> b(k, vector<int>(n, 0));
    for(int j = 0; j < k; ++j){
        int curr = 0;
        for(int i = 0; i < n; ++i){
            curr |= a[j][i];
            b[j][i] = curr;
        }
    }
    
    while(q--){
        int m;
        cin >> m;
        
        int l = 1, r = n;
        bool ok = false;
        
        for(int i = 0; i < m; ++i){
            char o;
            ll c, r;
            cin >> r >> o >> c;
            int region = r - 1; 
            
            if(o == '<'){
                int pos = lower_bound(all(b[region]), (int)c) - b[region].begin();
                if(pos == 0){
                    ok = true;
                    for(int rem = i + 1; rem < m; rem++){
                        char oo;
                        ll cc, rr;
                        cin >> rr >> oo >> cc;
                    }
                    break;
                } else{
                    r = min(r, 1LL * pos);
                }
            } else if(o == '>'){
                int pos = upper_bound(all(b[region]), (int)c) - b[region].begin();
                if(pos == n){
                    ok = true;
                    for(int rem = i + 1; rem < m; rem++){
                        char oo;
                        ll cc, rr;
                        cin >> rr >> oo >> cc;
                    }
                    break;
                } else{
                    l = max(l, pos +1);
                }
            }
        }
        
        if(ok || l > r){
            cout << "-1\n";
        } else{
            cout << l << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    // cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}