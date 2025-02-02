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
    int n, a, b;
    cin >> n >> a >> b;

    int mn = INT_MAX;
    multiset<int> st;
    for (int i = 0; i < n * n; i++) {
        int x;
        cin >> x;
        st.insert(x);
        mn = min(mn, x);
    }

    vector<vector<int>> mat(n, vector<int>(n));
    mat[0][0] = mn;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0)   continue;
            
            if (i == 0) 
                mat[i][j] = mat[i][j - 1] + b;
            else if (j == 0)    
                mat[i][j] = mat[i - 1][j] + a;
            else 
                mat[i][j] = mat[i - 1][j - 1] + b + a;
        }
    }

    for (auto x: mat) {
        for (auto y: x) {
            if (st.count(y) == 0) {
                cout << "NO\n";
                return;
            }
            st.erase(st.find(y));
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}