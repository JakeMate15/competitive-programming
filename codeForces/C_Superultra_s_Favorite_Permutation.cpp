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
    int n;
    cin >> n;

    if (n < 5) {
        cout << "-1\n";
        return;
    }

    vector<int> pa, im;
    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            im.push_back(i);
            if (i == 5) {
                swap(im.back(), im[0]);
            } 
        } else {
            pa.push_back(i);
            if (i == 4) {
                swap(pa[0], pa.back());
            }
        }
    }

    swap(pa[0], pa.back());

    for (auto x: pa) {
        cout << x << " ";
    }
    for (auto x: im) {
        cout << x << " ";
    }
    cout << "\n";
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