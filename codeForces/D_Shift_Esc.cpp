#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t; cin >> t;
    while(t--){
        int n, m;
        ll k;
        cin >> n >> m >> k;
        vector<vector<ll>> a(n, vector<ll>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
 
        vector<vector<vector<ll>>> cost(n, vector<vector<ll>>(m, vector<ll>(m, 1e18)));
        for (int i = 0; i < n; i++){
            vector<ll> dbl(2 * m);
            for (int j = 0; j < m; j++){
                dbl[j] = a[i][j];
                dbl[j + m] = a[i][j];
            }
            vector<ll> pref(2 * m + 1, 0);
            for (int j = 0; j < 2 * m; j++){
                pref[j + 1] = pref[j] + dbl[j];
            }
            for (int r = 0; r < m; r++){
                for (int L = 0; L < m; L++){
                    for (int R = L; R < m; R++){
                        ll sumBlock = pref[r + R + 1] - pref[r + L];
                        cost[i][L][R] = min(cost[i][L][R], k * (ll)r + sumBlock);
                    }
                }
            }
        }
 
        const ll INF = 1e18;
        vector<vector<ll>> dp(n, vector<ll>(m, INF));
        for (int j = 0; j < m; j++){
            dp[0][j] = cost[0][0][j];
        }
 
        for (int i = 1; i < n; i++){
            for (int prev = 0; prev < m; prev++){
                if(dp[i - 1][prev] == INF) continue;
                for (int j = prev; j < m; j++){
                    dp[i][j] = min(dp[i][j], dp[i - 1][prev] + cost[i][prev][j]);
                }
            }
        }
 
        cout << dp[n - 1][m - 1] << "\n";
    }
    return 0;
}
