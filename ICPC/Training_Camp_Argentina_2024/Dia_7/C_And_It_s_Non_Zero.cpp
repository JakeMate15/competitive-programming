#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define all(v)          v.begin(), v.end()
#define sz(a)           (int)a.size()

const int mx = 2E5 + 5;
vector<vector<int>> pref(mx, vector<int>(19));

void sol() {
    int l, r;
    cin >> l >> r;
    
    int re = 0;
    for (int i = 0; i < 19; i++) {
        int prend = pref[r][i] - pref[l - 1][i]; 
        // cerr << prend << "\n";
        re = max(re, prend);
    }

    cout << r - l + 1 - re << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    for (int i = 1; i < mx; i++) {
        for (int j = 0; j <= 18; j++) {
            if ((1 << j) & i) {
                pref[i][j]++;
            }
        }
    }

    for (int i = 1; i < mx; i++) {
        for (int j = 0; j <= 18; j++) {
            pref[i][j] += pref[i - 1][j];
        }
    }

    while(t--) {
        sol();
    }

    return 0;
}