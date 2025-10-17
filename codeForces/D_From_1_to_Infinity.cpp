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

vector<int64_t> pot(20,1), fp(20,0);

int64_t pref(int64_t n) {
    if (n < 0)
        return 0;
    if(n < 10) 
        return n * (n + 1) / 2;
    
    int d = 0;
    int64_t p = 1;
    while(p * 10 <= n) { 
        p *=10; 
        d++; 
    }

    int64_t msd = n / p;
    int64_t rest = n % p;
    return msd * fp[d] + (msd * (msd - 1) / 2) * p + msd * (rest + 1) + pref(rest);
}

int64_t get(int64_t a, int64_t b){
    if(a > b) 
        return 0;
    return pref(b) - pref(a - 1);
}

void sol () {
    int64_t x; 
    cin >> x;
    
    int64_t ans = 0, k = 1;
    while(true){
        int64_t cnt = 9 * pot[k - 1];
        int64_t d = k * cnt;
        if(x >= d){
            int64_t a = pot[k - 1];
            int64_t b = pot[k] - 1;
            ans += get(a, b);
            x -= d;
            k++;
        } else {
            int64_t t = x / k;
            int64_t r = x % k;
            int64_t a = pot[k - 1];
            if(t > 0) 
                ans += get(a, a + t - 1);
            if(r > 0) {
                int64_t nxt = a + t;
                string s = to_string(nxt);
                for(int64_t i = 0; i < r; i++) 
                    ans += s[i] - '0';
            }
            cout << ans << "\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i < 20; i++) 
        pot[i] = pot[i - 1] * 10;
    for (int d = 1; d < 20; d++) 
        fp[d] = 1LL * d * 45 * pot[d - 1];

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}
