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

    vector<int> cnt(26);
    for (auto x: s) {
        cnt[x - 'a']++;
    }

    string res = "";
    while (n) {
        for (int i = 0; i < 26; i++) {
            if (cnt[i]) {
                res += ('a' + i);
                cnt[i]--;
                n--;
            }
        }
    }

    cout << res << "\n";
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