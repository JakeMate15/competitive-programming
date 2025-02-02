#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

typedef pair<int, int> ii;

void sol () {
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<int> g[n + 1];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    int ans = 0;
    function<map<int, ii>(int, int)> dfs = [&] (int u, int p) -> map<int, ii> {
        map<int, ii> primeFactor;
        int ai = arr[u];
        for (int i = 2; i * i <= ai; i++) {
            if (ai % i == 0) {
                primeFactor[i] = {0, 0};
                while (ai % i == 0) {
                    ai /= i;
                }
            }
        }

        if (ai > 1) {
            primeFactor[ai] = {0, 0};
        }

        for (int v: g[u]) {
            if (v != p) {
                auto childAns = dfs(v, u);
                for (auto [p, MAX_SECOND]: childAns) {
                    if (primeFactor.count(p)) {
                        auto &[mx, snd] = primeFactor[p];
                        int currentDeph = MAX_SECOND.first + 1;
                        if (currentDeph > mx) {
                            snd = mx;
                            mx = currentDeph;
                        } else if (currentDeph > snd) {
                            snd = currentDeph;
                        }
                    }
                }
            }
        }

        for (auto &[p, MAX_SECOND]: primeFactor) {
            auto [mx, second] = MAX_SECOND;
            ans = max(ans, mx + second + 1);
        }

        return primeFactor;
    };

    dfs(1, 0);

    cout << ans << "\n";
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