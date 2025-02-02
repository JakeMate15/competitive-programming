#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
#endif

template <int p> 
struct mod_int {
    int64_t expo(int64_t b, int64_t e) {
        int64_t ret = 1;
        while (e) {
            if (e % 2) ret = ret * b % p;
            e /= 2, b = b * b % p;
        }
        return ret;
    }
    int64_t inv(int64_t b) { return expo(b, p - 2); }
 
    using m = mod_int;
    int v;
    mod_int() : v(0) {}
    mod_int(int64_t v_) {
        if (v_ >= p or v_ <= -p) v_ %= p;
        if (v_ < 0) v_ += p;
        v = v_;
    }
    m& operator +=(const m& a) {
        v += a.v;
        if (v >= p) v -= p;
        return *this;
    }
    m& operator -=(const m& a) {
        v -= a.v;
        if (v < 0) v += p;
        return *this;
    }
    m& operator *=(const m& a) {
        v = v * int64_t(a.v) % p;
        return *this;
    }
    m& operator /=(const m& a) {
        v = v * inv(a.v) % p;
        return *this;
    }
    m operator -(){ return m(-v); }
    m& operator ^=(int64_t e) {
        if (e < 0) {
            v = inv(v);
            e = -e;
        }
        v = expo(v, e%(p-1));
        return *this;
    }
    bool operator ==(const m& a) { return v == a.v; }
    bool operator !=(const m& a) { return v != a.v; }
 
    friend m operator +(m a, m b) { return a += b; }
    friend m operator -(m a, m b) { return a -= b; }
    friend m operator *(m a, m b) { return a *= b; }
    friend m operator /(m a, m b) { return a /= b; }
    friend m operator ^(m a, int64_t e) { return a ^= e; }

    friend ostream& operator<<(ostream& os, const m& a) {
        os << a.v;
        return os;
    }

    friend istream& operator>>(istream& is, m& a) {
        int64_t val;
        is >> val;
        a = m(val);
        return is;
    }
};
 
const int MOD = 1E9 + 7;
typedef mod_int<MOD> mint;

void sol () {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &x: arr) {
        cin >> x;
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