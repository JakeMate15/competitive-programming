#include<bits/stdc++.h>
using namespace std;

#define all(v)  v.begin(), v.end()
#define sz(a)   (int)a.size()

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> ii;
typedef vector<vector<int>> vvi;

const ld eps = 1e-9, inf = numeric_limits<ld>::max();
bool leq(ld a, ld b){return b-a >= -eps;}

void sol () {
    int n, r;
    cin >> n >> r;

    ld x, maxy;
    vector<ld> ys;
    vector<ii> centros, op;

    for (int i = 0; i < n; i++) {
        op.clear();
        ys.clear();

        cin >> x;

        for (auto c: centros) {
            if(leq(abs(x - c.first), 2.0 * r)) 
                op.push_back(c);
        }
        if(op.empty()) {
            centros.emplace_back(x, ld(r));
            continue;
        }

        maxy = 0.0;
        for (auto [a, b]: op) {
            ys.push_back(b + sqrt(4.0 * r * r - (x - a) * (x - a)));
        }

        for (auto y : ys) {
            maxy = max(maxy, y);
        }

        centros.emplace_back(x, maxy);
    }

    for (auto [a, b]: centros) {
        cout << b << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);

    while(t--) {
        sol();
    }

    return 0;
}