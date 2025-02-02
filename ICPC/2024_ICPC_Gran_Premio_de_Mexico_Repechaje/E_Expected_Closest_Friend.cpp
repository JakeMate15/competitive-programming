#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

template <int p>
struct mod_int {
    ll expo(ll b, ll e) {
        ll ret = 1;
        while (e) {
            if (e % 2) ret = ret * b % p;
            e /= 2, b = b * b % p;
        }
        return ret;
    }
    ll inv(ll b) { return expo(b, p-2); }

    using m = mod_int;
    int v;
    mod_int() : v(0) {}
    mod_int(ll v_) {
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
        v = v * ll(a.v) % p;
        return *this;
    }
    m& operator /=(const m& a) {
        v = v * inv(a.v) % p;
        return *this;
    }
    m operator -() { return m(-v); }
    m& operator ^=(ll e) {
        if (e < 0) {
            v = inv(v);
            e = -e;
        }
        v = expo(v, e % (p - 1));
        return *this;
    }
    bool operator ==(const m& a) { return v == a.v; }
    bool operator !=(const m& a) { return v != a.v; }

    friend m operator +(m a, m b) { return a += b; }
    friend m operator -(m a, m b) { return a -= b; }
    friend m operator *(m a, m b) { return a *= b; }
    friend m operator /(m a, m b) { return a /= b; }
    friend m operator ^(m a, ll e) { return a ^= e; }
};

const int MOD = 1E9 + 7;
typedef mod_int<MOD> mint;

struct Combinatoria {
    int n;
    vector<mint> fact;
    vector<mint> inv_fact;

    Combinatoria(int max_n) {
        n = max_n;
        fact.assign(n + 1, 1);
        inv_fact.assign(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
            inv_fact[i] = 1 / fact[i];
        }
    }

    mint comb(int a, int b) {
        if (a < b || b < 0) return 0;
        return fact[a] / (inv_fact[b] * inv_fact[a - b]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> g[n + 1];
    for (int i = 0; i < m; i++) {
        int p, q, c;
        cin >> p >> q >> c;
        g[p].emplace_back(q, c);
        g[q].emplace_back(p, c);
    }

    vector<ll> d(n, 1e18);
    d[0] = 0;
    pqg<pair<ll, int>> pq;
    pq.emplace(0, 0);
    vector<bool> vis(n);
    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();
        if (vis[u]) {
            continue;
        }

        vis[u] = true;
        for (auto &[v, w] : g[u]) {
            if (!vis[v] && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.emplace(d[v], v);
            }
        }
    }

    map<ll, int> mp;
    for (int i = 1; i < n; i++) {
        mp[d[i]]++;
    }

    vector<pair<ll, int>> cnt(mp.begin(), mp.end());
    
    int s = cnt.size();
    vector<ll> cj(s, 0LL);
    ll tot = n - 1;
    ll sum = 0;
    for (int j = 0; j < s; j++) {
        cj[j] = tot - sum;
        sum += cnt[j].second;
    }

    Combinatoria combi(n);
    mint Ck = combi.comb(n - 1, k);

    mint sum1 = 0;
    mint sum2 = 0;
    ll pl = 1;
    ll md = cnt.back().first;
    for (int j = 0; j < s; j++) {
        ll cl = cnt[j].first;
        if (cl > pl) {
            mint r = cl - pl;
            sum1 += r;
        }
        ll sigL = (j < s - 1) ? cnt[j + 1].first : (md + 1);
        mint r2 = sigL - cl;
        mint CK = combi.comb(cj[j], k);
        sum2 += r2 * CK;
        pl = sigL;
    }

    mint E = sum1 + sum2 / Ck;
    cout << E.v << "\n";

    return 0;
}