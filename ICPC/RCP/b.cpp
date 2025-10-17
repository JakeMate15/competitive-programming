#include<bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << fixed << setprecision(10);

    int n;
    double p;
    cin >> n >> p;
    
    double A = 0, B = 0;
    vector<array<double, 2>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
        a[i][1] *= a[i][0];
        A += a[i][0];
        B += a[i][1];
    }
    
    sort(all(a), [&](const auto& L, const auto& R) {
        return L[1] / L[0] > R[1] / R[0];
    });

    if (a[0][1] / a[0][0] < p) {
        cout << 0 << '\n';
        return 0;
    }

    if (B / A > p) {
        reverse(a.begin(), a.end());
        double low = 0, high = A;
        for (int k = 0; k < 60; ++k) {
            double mid = (low + high) / 2;
            double v = 0, rem = mid;
            for (auto [A, B] : a) {
                double used = min(rem, A);
                v += B / A * used;
                rem -= used;
            }
            if (v / mid > p) {
                high = mid;
            } else {
                low = mid;
            }
        }
        cout << high << '\n';
        return 0;
    }

    double low = 0, high = A;
    for (int k = 0; k < 60; ++k) {
        double mid = (low + high) / 2;
        double v = 0, rem = mid;
        for (auto [A, B] : a) {
            double used = min(rem, A);
            v += B / A * used;
            rem -= used;
        }
        if (v / mid < p) {
            high = mid;
        } else {
            low = mid;
        }
    }
    cout << high << '\n';

    return 0;
}
