#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
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
    int64_t n;
    cin >> n;

    auto ok = [] (int64_t x) -> bool {
        int64_t sq = sqrtl(x);
        return sq * sq == x;
    };

    int64_t total = 1LL * n * (n + 1) / 2;
    if(ok(total)){
        cout << -1 << "\n";
        return;
    }

    vector<int> p(n);
    for (int i = 0; i < n; i++){
        p[i] = i + 1;
    }

    int64_t s = 0;
    for (int i = 0; i < n - 1; i++){
        if(ok(s + p[i])){
            swap(p[i], p[i + 1]);
        }
        s += p[i];
    }
    for(auto x : p)
        cout << x << " ";
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