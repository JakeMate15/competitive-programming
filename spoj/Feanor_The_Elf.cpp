#include<bits/stdc++.h>

using namespace std;
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

ll v, h;
const ld g = 9.8;

ld f(ld a) {
    ld ang = (1.0 * acos(-1) * a) / 180.0;

    ld vy = sin(ang) * v;
    ld vx = cos(ang) * v;
    ld t1 = (vy - sqrt(vy * vy + 2.0 * g * h)) / g;
    ld t2 = (vy + sqrt(vy * vy + 2.0 * g * h)) / g;

    ld t = max(t1, t2);
    
    return vx * t;
}

void sol() {
    if (v == -1 && h == -1) {
        return;
    }

    ld l = 0, r = 90;
    for (int i = 0; i <= 50; i++) {
        ld m1 = l + (r - l) / 3.0;
        ld m2 = r - (r - l) / 3.0;

        if (f(m1) < f(m2))
            l = m1;
        else 
            r = m2;
    }

    cout << fixed << setprecision(6) << f((l + r) / 2) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;

    while(cin >> v >> h) {
        sol();
    }

    return 0;
}