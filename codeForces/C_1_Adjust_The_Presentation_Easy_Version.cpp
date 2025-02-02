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
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n), b(m);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: b) {
        cin >> x;
    }

    int i = 0;
    set<int> st;
    for (int j = 0; j < m; j++) {
        if (st.count(b[j])) {

        } else if (b[j] == a[i]) {
            st.insert(b[j]);
            i++;
        } else {
            cout << "TIDAK\n";
            return;
        }
    }

    cout << "YA\n";
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