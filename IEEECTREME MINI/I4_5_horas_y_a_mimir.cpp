#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    // #include "algoDebug.h"
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
    int n, r;
    cin >> n >> r;
    vector<int> arr(n);
    for (auto &x: arr) {
        cin >> x;
    }

    sort(all(arr));

    vector<int> p;
    vector<bool> vis(n, false);

    function<void()> dfs = [&](void) {
        if(sz(p) == r) {
            for(int i = 0; i < r; ++i) {
                cout << p[i] << (i == r - 1 ? '\n' : ' ');
            }
            return; 
        }
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                vis[i] = true;
                p.push_back(arr[i]);
                dfs();
                p.pop_back();
                vis[i] = false;
            }
        }
    };

    dfs();
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