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

void sol() {
    int n;
    string s;
    cin >> n >> s;

    int sq = sqrt(n);
    if (sq * sq != n) {
        cout << "No\n";
        return;
    }

    bool ok = true;
    for (int j = 0; j < sq; j++) {
        if (s[j] != '1' || s[(sq - 1) * sq + j] != '1') {
            ok = false;
            break;
        }
    }

    for (int i = 0; i < sq; i++) {
        if (s[i * sq] != '1' || s[i * sq + sq - 1] != '1') {
            ok = false;
            break;
        }
    }

    if (ok) {
        for (int i = 1; i < sq - 1; i++) {
            for (int j = 1; j < sq - 1; j++) {
                if (s[i * sq + j] != '0') {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }
    }

    if (ok) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
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