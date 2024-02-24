#include<bits/stdc++.h>
using namespace std;

#define sz(a)   (int) a.size()
#define nl      "\n"
#define all(a)  a.begin(), a.end()

typedef long long ll;

struct st{
    ll lo, hi;
    st *l, *r;
    vector<int> b;

    st(vector<ll>::iterator from, vector<ll>::iterator to, ll x, ll y) {
        lo = x, hi = y;
        if (lo == hi or from >= to) return;
        int mid = (lo + hi) / 2;
        auto f = [mid](int x) {return x <= mid;};
        b.reserve(to - from + 1);
        b.push_back(0);
        for (auto it = from; it != to; it++) 
            b.push_back(b.back() + f(*it));
        auto pivot = stable_partition(from, to, f);
        l = new st(from, pivot, lo, mid);
        r = new st(pivot, to, mid + 1, hi);
    }

    ll query(int l, int r, int k) {
        if (l > r)  return 0;
        if(lo == hi)    return lo;
        int inLeft = b[r] - b[l - 1];
        int lb = b[l - 1];
        int rb = b[r];
        if (k <= inLeft)    return this -> l -> query(lb + 1, rb, k);
        return this->r->query(l - lb, r - rb, k - inLeft);
    }
};

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<ll> a(n), aux;
    ll mn = LONG_LONG_MAX, mx = LONG_LONG_MIN;
    for (auto &x: a) {
        cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
    }

    aux = a;

    st s(a.begin(), a.end(), mn, mx);
    while(q--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        
        // cout << s.query(l, r, k) << nl;
        if (l == r) {
            cout << aux[l] << nl;
        }
        else {
            cout << s.query(l, r, k) << nl;
        }
    }
}