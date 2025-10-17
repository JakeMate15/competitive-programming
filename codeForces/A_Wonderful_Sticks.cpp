#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include "/algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

void sol () {
    int n;
    string s;
    cin >> n >> s;

    int L = count(s.begin(), s.end(), '<');
    vector<int> l, u, ans;
    for (int x = L; x >= 1; x--) 
        l.push_back(x);
    for (int x = L + 2; x <= n; x++) 
        u.push_back(x);
    int li = 0, ui = 0;
    ans.push_back(L + 1);
    for (char c : s) {
        if (c == '<') 
            ans.push_back(l[li++]);
        else 
            ans.push_back(u[ui++]);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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