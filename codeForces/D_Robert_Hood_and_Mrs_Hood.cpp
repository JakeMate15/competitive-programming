#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void sol () {
    ll n, d, k;
    cin >> n >> d >> k;

    ll m = n - d + 1;
    if (m < 1) {
        m = 1;
    }

    vector<ll> difs(m +2, 0);
    for(ll i = 0; i < k; i++){
        ll li, ri;
        cin >> li >> ri;
        ll ini = max(1LL, li - d + 1);
        ll fin = min(1LL * n - d + 1, ri);
        if(ini > fin){
            continue; 
        }
        difs[ini]++;
        difs[fin + 1]--;
    }

    vector<ll> cnt(m + 1, 0);
        cnt[1] = difs[1];
        for(ll s = 2; s <= m; s++){
            cnt[s] = cnt[s - 1] + difs[s];
        }

        ll mxCnt = -1;
        ll res1 =1;
        for(ll s = 1; s <= m; s++){
            if(cnt[s] > mxCnt){
                mxCnt = cnt[s];
                res1 = s;
            }
        }
        ll mn = LLONG_MAX;
        ll res2 = 1;
        for(ll s = 1; s <= m; s++){
            if(cnt[s] < mn){
                mn = cnt[s];
                res2 = s;
            }
        }
        cout << res1 << " " << res2 << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}
