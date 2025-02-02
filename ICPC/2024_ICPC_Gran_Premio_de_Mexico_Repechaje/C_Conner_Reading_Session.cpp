#include<bits/stdc++.h>
using namespace std;

int get (int cap, int n, const vector<int> &w, const vector<int> &v, vector<vector<int>> &dp) {
    if (cap == 0 || n == 0) {
        return 0;
    }

    int &mem = dp[cap][n];
    if (mem != -1) {
        return mem;
    }

    if (w[n] > cap || w[n] > 480) {
        return mem = get(cap, n - 1, w, v, dp);
    }

    return max (
        v[n] + get(cap - w[n], n - 1, w, v, dp),
        get(cap, n - 1, w, v, dp)
    );
}

int main() {
    int n;
    cin >> n;

    vector<int> B(n + 1), P(n + 1), F(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
        B[i] *= 3;
    }
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> F[i];
    }

    vector<vector<int>> dp1(781, vector<int>(n + 1, -1)), dp2(781, vector<int>(n + 1, -1));
    int p = get(780, n, B, P, dp1);
    int f = get(780, n, B, F, dp2);

    // cerr << p << " " << f << "\n";
    
    if (p > f) {
        cout << "PLEASURE\n";
    } else if (p < f) {
        cout << "FAME\n";
    } else {
        cout << "EITHER\n";
    }

    return 0;
}
