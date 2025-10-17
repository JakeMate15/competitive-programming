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

    vector<int> arr(n+1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    int T = 2 * n;
    vector<int> seq(T, 0), pre(T, 0);
    for(int i = 1; i <= n; i++){
        seq[i] = arr[i];
        pre[i] = (i == 1 ? seq[i] : pre[i - 1] ^ seq[i]);
    }
    for(int m = n + 1; m < T; m++){
        int idx = m / 2;
        seq[m] = pre[idx];
        pre[m] = pre[m-1] ^ seq[m];
    }

    vector<int64_t> s1(T, 0);
    for(int i = 1; i < T; i++){
        s1[i] = s1[i - 1] + seq[i];
    }

    vector<int> preP(T, 0);
    for(int i = 1; i < T; i++){
        preP[i] = s1[i] & 1;
    }

    vector<int64_t> preCnt(T, 0);
    for(int i = 1; i < T; i++){
        preCnt[i] = preCnt[i - 1] + (preP[i] == 1);
    }

    int B0 = preP[T - 1];
    function<int(int64_t)> get = [&](int64_t x) -> int {
        if(x < T) return preP[x];
        if(x & 1LL) return B0;
        return B0 ^ get(x / 2);
    };

    function<int64_t(int64_t, int64_t, int)> get2 = [&](int64_t L, int64_t R, int tVal) -> int64_t {
        if(L > R) return 0LL;
        if(R < T) {
            int64_t unos = preCnt[(int)R] - (L > 1 ? preCnt[L - 1] : 0LL);
            int64_t total = R - L + 1;
            return tVal == 1 ? unos : total - unos;
        }
        if(L < T && R >= T){
            int64_t p1 = 0;
            if(T - 1 >= L){
                int64_t unos = preCnt[T - 1] - (L > 1 ? preCnt[L - 1] : 0LL);
                int64_t total = T - L;
                p1 = tVal == 1 ? unos : total - unos;
            }
            return p1 + get2(T, R, tVal);
        }
        int64_t ans = 0;
        int64_t impar = ((R + 1LL) / 2) - (L / 2);
        if(B0 == tVal) {
            ans += impar;
        }
        int64_t par = (L % 2 == 0 ? L : L + 1);
        if(par <= R){
            int64_t nL = par / 2, nR = R / 2;
            ans += get2(nL, nR, B0 ^ tVal);
        }
        return ans;
    };

    function<int64_t(int64_t)> getR = [&](int64_t x) -> int64_t {
        if(x < 1) return 0LL;
        if(x < T) return s1[x];
        int64_t base = s1[T - 1];
        if((x & 1LL) == 0){
            int64_t K = x / 2;
            int64_t otro = 2LL * get2(n, K - 1, 1) + get(K);
            return base + otro;
        } else {
            int64_t K = (x - 1) / 2;
            int64_t otro = 2LL * get2(n, K, 1);
            return base + otro;
        }
    };

    cout << getR(r) - getR(l - 1) << "\n";
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