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
    int64_t n, l, r;
    cin >> n >> l >> r;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> p(n + 1, 0);
    for (int i = 1; i <= n; i++){
        p[i] = p[i - 1] ^ a[i];
    }
    
    if(l <= 1LL * n){
        cout << a[l] << "\n";
        return;
    }

    int c = (n & 1 ? p[n] : p[n] ^ p[n / 2]);
    function<int(int64_t)> get = [&](int64_t x) -> int {
        if(x <= 1LL * n) 
            return p[x];
        if(x & 1LL) 
            return c;
        else 
            return c ^ get(x/2);
    };

    int64_t idx = l / 2;
    cout << get(idx) << "\n";
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