#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

void sol () {
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)    
        cin >> a[i];
    for (int i = 1; i <= n; i++)    
        cin >> b[i];

    auto get = [&] (vector<int> arr) -> int {
        int res = 0;
        vector<bool> vis(n + 1);
    
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;

            int cnt = 0;
            for (int curr = i; !vis[curr]; curr = arr[curr]) {
                cnt++;
                vis[curr] = true;
            }

            res += max(0, cnt - 1);
        }

        return res;
    };

    cout << get(a) + get(b) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    // cin >> tt;

    while (tt--) {
        sol();
    }
}   