#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(), v.end()
#define sz(a)           (int)a.size()

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<vector<int>> vvi;

void sol () {
    int n, x;
    cin >> n >> x;

    if (x > n - 1) {
        cout << -1 << "\n";
        return;
    }

    vvi a(n), b(n);
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            a[i].push_back(cnt);
            b[(i + j) % n].push_back(cnt);
            cnt++;
        }
    }

    vector<int> res(x * n + 1);
    for (int i = 1; i <= x * n; i++)
        res[i] = i;
    
    random_shuffle(res.begin() + 1, res.end());
  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < x; j++) {
            cout << res[a[i][j]] << " ";
        }
        
        for (int j = 0; j < x; j++) {
            cout << res[b[i][j]] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}
