#include <bits/stdc++.h>
using namespace std;

#define sz(a)   (int) a.size()
#define all(a)  a.begin(), a.end()

typedef long long ll;
typedef pair<int, int> pi;

const int MAXN = 1E5 + 5;
const int LOG = 18;
int n, m;
int st[MAXN][LOG];
int LG[MAXN];

void build(vector<int>& a) {
    LG[1] = 0;
    for (int i = 2; i < MAXN; i++) {
        LG[i] = LG[i/2] + 1;
    }

    for (int i = 0; i < m; i++) {
        st[i][0] = a[i];
    }
    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i + (1 << j) <= m; i++) {
            st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
        }
    }
}

int rmq(int l, int r) {
    int j = LG[r - l + 1];
    return min(st[l][j], st[r - (1 << j) + 1][j]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    vector<ll> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    build(b);

    for (int i = 0; i < n; i++) {
        int l = 0;
        while (a[i] > 0) {
            int lo = l, hi = m - 1, res = -1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (rmq(l, mid) <= a[i]) {
                    res = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            if (res == -1) break;
            l = res + 1;
            a[i] %= b[res];
        }
    }

    for (int i = 0; i < n; i++) 
        cout << a[i] << " ";

    return 0;
}
