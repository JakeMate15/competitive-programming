#include<bits/stdc++.h>
using namespace std;

#define sz(a)   (int) a.size()
#define all(a)  a.begin(), a.end()

typedef long long ll;
typedef pair<int, int> pi;

int main () {
    int n, t;
    cin >> n >> t;

    vector<double> s = {0, 0};
    for (int i = 0; i < n; i++) {
        char c;
        double x;
        cin >> c >> x;

        s[c == 'P'] += x;
    }

    vector<double> mn = {s[0] / (0.25 * t), s[1] / (0.75 * t)};
    double res = 0, eps = 1e-9;

    if (mn[0] + eps < mn[1]) {
        auto xd = s[1] - (0.75 * t * mn[0]);
        res = ((xd / t) + mn[0]);
    } 
    else {
        auto xd = s[0] - (0.25 * t * mn[1]);
        res = ((xd / t) + mn[1]);
    }

    cout << fixed << setprecision(10) << res << "\n";
}