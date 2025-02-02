#include <bits/stdc++.h>
using namespace std;

using ld = long double;
const ld eps = 1e-9, inf = numeric_limits<ld>::max(), pi = acos(-1);
bool geq(ld a, ld b){return a-b >= -eps;}     //a >= b
bool leq(ld a, ld b){return b-a >= -eps;}     //a <= b
bool ge(ld a, ld b){return a-b > eps;}        //a > b
bool le(ld a, ld b){return b-a > eps;}        //a < b
bool eq(ld a, ld b){return abs(a-b) <= eps;}  //a == b
bool neq(ld a, ld b){return abs(a-b) > eps;}  //a != b

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    ld d, p, e;
    cin >> d >> p >> e;

    vector<int> b(n);
    for(auto &x: b) {
        cin >> x;
    }

    sort(b.begin(), b.end(), ge);

    vector<ld> pref(n + 1, 0.0);
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + 1.0 / b[i - 1];
    }

    auto get = [&](ld a) -> ld {
        ld E = 0.0;
        ld da = d * a;
        int k_d = upper_bound(b.begin(), b.end(), da) - b.begin();
        ld sum_d = pref[n] - pref[k_d];
        ld k_1 = upper_bound(b.begin(), b.end(), a) - b.begin();
        ld sum_1 = pref[n] - pref[k_1];
        E = p * (k_d + da * sum_d) + (1.0 - p) * (k_1 + a * sum_1);
        return E;
    };

    if(e ==0.0){
        cout << 0 << "\n";
        return 0;
    }

    ld lo = 0.0, hi = 1E14;
    for(int i = 0; i < 100; i++){
        ld mid = (lo + hi) / 2.0;
        ld E = get(mid);
        if(geq(E, e)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    ld a = hi;
    if(geq(e, n)){
        ld max_b = *max_element(b.begin(), b.end());
        a = max(max_b / d, max_b * 1.0);
    }
    cout << fixed << setprecision(20) << a;
}