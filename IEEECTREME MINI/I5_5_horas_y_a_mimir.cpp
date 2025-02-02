#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    // #include "algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

void sol () {
    int n;
    cin >> n;

    vector<tuple<int, int, int>> arr(n);
    for (auto &[a, b, c]: arr) {
        cin >> a >> b >> c;
    }

    sort(all(arr), [] (tuple<int, int, int> a, tuple<int, int, int> b) {
        auto [a1, b1, c1] = a;
        auto [a2, b2, c2] = b;

        ld s1 = a1 + b1 + c1;
        s1 /= 3.0;

        ld s2 = a2 + b2 + c2;
        s2 /= 3.0;

        ld aa1 = sqrt(s1 * (s1 - a1) * (s1 - b1) * (s1 - c1));
        ld aa2 = sqrt(s2 * (s2 - a2) * (s2 - b2) * (s2 - c2));

        return aa1 < aa2;
    });

    for (auto &[a, b, c]: arr) {
        cout << a << " " << b << " " << c << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    // cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}