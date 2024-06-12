#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 120 + 5, Mod = 1e9 + 7;

inline ll power(ll x, ll y) {
    ll ret = 1;
    while (y) {
        if (y & 1) ret = ret * x % Mod;
        x = x * x % Mod, y >>= 1;
    }
    return ret;
}

inline ll inv(ll x) {
    return power(x, Mod - 2);
}

ll n = 0, m = 0, w = 0, o = 0, d = 0, r = 0, k = 0;
vector<ll> c(N), v(N), iv(N), binom(N, vector<ll>(N));
vector<vector<ll>> a(N, vector<ll>(N)), b(N, vector<ll>(N));
vector<vector<vector<vector<vector<ll>>>>> f(2, vector<vector<vector<vector<ll>>>>(2, vector<vector<vector<ll>>>(N, vector<vector<ll>>(N, vector<ll>(N)))));
vector<vector<vector<vector<vector<ll>>>>> g(2, vector<vector<vector<vector<ll>>>>(2, vector<vector<vector<ll>>>(N, vector<vector<ll>>(N, vector<ll>(N)))));
vector<vector<ll>> dp(N, vector<ll>(N));
vector<char> s(N);

inline void init() {
    n = m = w = o = d = r = k = 0;
    fill(c.begin(), c.end(), 0);
    fill(v.begin(), v.end(), 0);
    fill(s.begin(), s.end(), 0);
    for (auto &fi : f) for (auto &fii : fi) for (auto &fiii : fii) for (auto &fiv : fiii) fill(fiv.begin(), fiv.end(), 0);
    for (auto &gi : g) for (auto &gii : gi) for (auto &giii : gii) for (auto &giv : giii) fill(giv.begin(), giv.end(), 0);
    for (auto &dpi : dp) fill(dpi.begin(), dpi.end(), 0);
}

inline void solve() {
    cin >> n;
    v[0] = v[1] = 1;
    for (ll i = 1; i <= n; i++) {
        cin >> c[i];
        v[c[i]] = 1;
    }
    cin >> s.data() + 1;
    for (ll i = 1; i <= n; i++) {
        if (s[i] == '0') r++;
        if (c[i] > 1) w++;
        else if (c[i] == 1) {
            if (s[i] == '1') o++;
            m++;
        } else {
            if (s[i] == '1') d++;
            else k++;
        }
    }
    if (c[n] <= 1) {
        for (ll i = 1; i <= n; i++) if (s[i] == '0') {
            cout << "0\n";
            return;
        }
        cout << "1\n";
        return;
    }
    for (ll p = 0; p <= n; p++) for (ll u = 0; u <= c[n]; u++) if (v[u]) {
        f[1][0][u][p][0] = f[1][1][u][p][0] = 1;
        g[1][0][u][p][0] = g[1][1][u][p][0] = 1;
    }
    for (ll i = n, h = 0; c[i] > 1; i--) {
        for (ll p = 0; p <= n; p++) for (ll u = 0; u <= c[i]; u++) if (v[u]) {
            g[0][0][u][p][0] = 1;
            if (s[i] == '0') g[0][1][u][p][0] = g[1][1][u][p][0];
        }
        for (ll p = 0; p <= n; p++) for (ll u = 0; u <= c[i]; u++) if (v[u]) for (ll x = 1; x <= k; x++) {
            for (ll y = 0; y <= x - (c[i] - 1); y++) f[0][0][u][p][x] = (f[0][0][u][p][x] + (g[1][0][u][p][y] * g[0][0][c[i]][p - (c[i] - 1) - y][x - (c[i] - 1) - y] % Mod) * ((u + y) * b[p - y + 1][c[i]] % Mod)) % Mod;
            g[0][0][u][p][x] = (g[1][0][u][p][x] + f[0][0][u][p][x]) % Mod;
        }
        for (ll p = 0; p <= n; p++) for (ll u = 0; u <= c[i]; u++) if (v[u]) for (ll x = 1; x <= k; x++) {
            if (s[i] == '1') {
                for (ll y = h; y <= x - c[i]; y++) f[0][1][u][p][x] = (f[0][1][u][p][x] + (g[1][1][u][p][y] * g[0][0][c[i]][p - (c[i] - 1) - y + h][x - c[i] - y] % Mod) * b[p - y + 1 + h][c[i]]) % Mod;
                g[0][1][u][p][x] = f[0][1][u][p][x];
            } else {
                for (ll y = h; y <= x - (c[i] - 1); y++) f[0][1][u][p][x] = (f[0][1][u][p][x] + (g[1][1][u][p][y] * g[0][0][c[i]][p - (c[i] - 1) - y + h][x - (c[i] - 1) - y] % Mod) * ((u + y) * b[p - y + 1 + h][c[i]] % Mod)) % Mod;
                g[0][1][u][p][x] = (g[1][1][u][p][x] + f[0][1][u][p][x]) % Mod;
            }
        }
        for (ll p = 0; p <= n; p++) for (ll u = 0; u <= c[i]; u++) if (v[u]) for (ll x = 0; x <= k; x++) {
            f[1][0][u][p][x] = f[0][0][u][p][x], f[1][1][u][p][x] = f[0][1][u][p][x];
            g[1][0][u][p][x] = g[0][0][u][p][x], g[1][1][u][p][x] = g[0][1][u][p][x];
            f[0][0][u][p][x] = f[0][1][u][p][x] = g[0][0][u][p][x] = g[0][1][u][p][x] = 0;
        }
        if (s[i] == '1') h++;
    }
    for (ll i = 0; i <= k; i++) for (ll x = 0; x <= m - o; x++) dp[i][o + x] = g[1][1][0][r][i + x] * (binom[i + x][i] * a[m - o][x] % Mod) % Mod;
    for (ll i = 0; i <= k; i++) for (ll x = 1; x <= m; x++) if (dp[i][x]) {
        if (i < k) dp[i + 1][x - 1] = (dp[i + 1][x - 1] + dp[i][x] * iv[w + k - i]) % Mod;
        for (ll j = 0; i + j <= k; j++) for (ll y = 0; x + y - 1 <= m; y++) if (j + y > 1) dp[i + j][x + y - 1] = (dp[i + j][x + y - 1] + (dp[i][x] * g[1][0][1][n - d - i - x][j + y - 1] % Mod) * (iv[w + k - i] * (binom[j + y][j] * a[m - x + 1][y] % Mod) % Mod)) % Mod;
    }
    ll ans = 1;
    for (ll i = 0; i <= k; i++) ans = (ans + (Mod - dp[i][0]) * a[k][i]) % Mod;
    cout << ans << endl;
}

ll T = 0;

int main() {
    for (ll x = 0; x < N; x++) {
        a[x][0] = b[x][0] = 1, iv[x] = inv(x), binom[x][0] = 1;
        for (ll y = 1; y <= x; y++) {
            a[x][y] = a[x][y - 1] * (x - y + 1) % Mod, b[x][y] = inv(a[x][y]);
            binom[x][y] = (binom[x - 1][y - 1] + binom[x - 1][y]) % Mod;
        }
    }
    cin >> T;
    for (ll i = 1; i <= T; i++) init(), solve();
    return 0;
}
