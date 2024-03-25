#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> c(n);
    vector<string> palabras(n);
    ll dp[n][2];

    for(int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    for(int i = 0; i < n; ++i) {
        cin >> palabras[i];
    }

    dp[n][0] = dp[n][1] = 0;

    for(int i = n - 1; i >= 0; --i) {
        for(int j = 0; j < 2; ++j) {
            string anterior = i > 0 ? palabras[i-1] : "";
            if(j) reverse(all(anterior));

            ll res = 1E18;
            string act = palabras[i];

            if(anterior <= act) {
                res = min(res, dp[i + 1][0]);
            }

            reverse(all(act));
            if(anterior <= act) {
                res = min(res, dp[i + 1][1] + c[i]);
            }

            dp[i][j] = res;
        }
    }

    ll resultado = min(dp[0][0], dp[0][1] + c[0]);
    cout << (resultado == 1E18 ? -1 : resultado) << "\n";

    return 0;
}
