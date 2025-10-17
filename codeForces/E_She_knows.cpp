#include<bits/stdc++.h>
using namespace std;

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

const int MX = 2E5 + 5;
const int64_t MOD = 1E9 + 7;

struct mint {
    int64_t v;
    mint(int64_t _v = 0) {
        v = _v % MOD;
        if(v < 0) v += MOD;
    }
    mint operator+(const mint &o) const { return mint(v + o.v); }
    mint operator-(const mint &o) const { return mint(v - o.v); }
    mint operator*(const mint &o) const { return mint(v * o.v); }
    mint operator/(const mint &o) const { return *this * o.inv(); }
    mint pow(int64_t exp) const {
        mint base = *this, res = 1;
        while(exp > 0) {
            if(exp & 1) res = res * base;
            base = base * base;
            exp >>= 1;
        }
        return res;
    }
    mint inv() const { return pow(MOD - 2); }
    mint& operator+=(const mint &o) {
        v += o.v;
        if(v >= MOD) v -= MOD;
        return *this;
    }
    mint& operator-=(const mint &o) {
        v -= o.v;
        if(v < 0) v += MOD;
        return *this;
    }
    mint& operator*=(const mint &o) {
        v = (v * o.v) % MOD;
        return *this;
    }
    mint& operator/=(const mint &o) {
        *this = *this / o;
        return *this;
    }
    bool operator==(const mint &o) const { return v == o.v; }
    bool operator!=(const mint &o) const { return v != o.v; }
    mint operator-() const { return mint(-v); }
    friend ostream& operator<<(ostream &os, const mint &m) {
        os << m.v;
        return os;
    }
};

void sol () {
    int n, m, k;
    cin >> n >> m >> k;

    int64_t tOd = 0;
    int64_t totC = 1LL * n * m;
    int64_t vacias = totC - k;
    if(m > 2) tOd += 2 * (m - 2);
    if(n > 2) tOd += 2 * (n - 2);


    int64_t cnt = 0, s = 0;
    for(int i = 0; i < k; i++) {
        int64_t x, y, c;
        cin >> x >> y >> c;
        bool imp = false;
        if(x == 1 || x == n || y == 1 || y == m) {
            if(!((x == 1 && y == 1) || (x == 1 && y == m) || (x == n && y == 1) || (x == n && y == m)))
                imp = true;
        }
        if(imp) {
            cnt++;
            s ^= c;
        }
    }

    mint ans = 0;
    if(tOd > cnt) {
        ans = mint(2).pow(vacias - 1);
    } else {
        ans = (s == 0 ? mint(2).pow(vacias) : 0);
    }

    cout << ans << "\n";
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