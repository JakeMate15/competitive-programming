#include<bits/stdc++.h>
using namespace std;

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

typedef long double ld;
typedef pair<int, int> ii;

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

void sol () {
    int64_t n, k, l;
    cin >> n >> k >> l;

    int64_t ans;
    if(k > 2LL * l){
        ans = n * 4LL * l * l;
    }
    else{
        int64_t extra = (2ll * l - k) * (2ll * l - k);
        ans = n * 4ll * l * l - (n - 1) * extra;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    // cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}