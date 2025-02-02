#include<bits/stdc++.h>
using namespace std;

const int P = 239017, MOD_X = 1e9 + 7, MOD_Y = 1e9 + 9, N = 3e6 + 5;
// using H = unsigned long long;
struct H {
    int x, y;
    H() = default;
    H(int _x): x(_x), y(_x) {}
    H(int _x, int _y): x(_x), y(_y) {}
    H operator+(const H& h) const { return H(add(x, h.x, MOD_X), add(y, h.y, MOD_Y)); }
    H operator-(const H& h) const { return H(sub(x, h.x, MOD_X), sub(y, h.y, MOD_Y)); }
    H operator*(const H& h) const { return H(mul(x, h.x, MOD_X), mul(y, h.y, MOD_Y)); }
    bool operator==(const H& h) const { return x == h.x && y == h.y; }
 // bool operator!=(const H& h) const { return x != h.x || y != h.y; }
    bool operator<(const H& h) const {if (x == h.x) {return y < h.y; } return x < h.x; }

    static int64_t add(int64_t a, int64_t b, int64_t mod) {
        a += b;
        return a >= mod ? a - mod : a;
    }

    static int64_t sub(int64_t a, int64_t b, int64_t mod) {
        a -= b;
        return a < 0 ? a + mod : a;
    }

    static int64_t mul(int64_t a, int64_t b, int64_t mod) {
        return ((int64_t(1) * a * b) % mod);
    }
};

H p[N], h[N];

// Query desde 0, [l, r)
H get(int l, int r) { 
    return h[r] - h[l] * p[r - l]; 
}

void init(const string& s) {
    int n = s.size();
    p[0] = 1;
    for (int i = 0; i < n; i++)
        h[i + 1] = h[i] * P + s[i], p[i + 1] = p[i] * P;
}

int maxPalindromes(string s, int k) {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;

    while(t--) {
        string s;
        int k;
        cin >> s >> k;

        cout << maxPalindromes(s, k) << "\n";
    }

    return 0;
}