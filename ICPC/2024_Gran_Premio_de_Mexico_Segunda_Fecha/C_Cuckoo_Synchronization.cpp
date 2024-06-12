#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

void sol() {
    ll n, t;
    cin >> n >> t;

    if (t == 1) {
        cout << n << "\n";
        return;
    }

    t--;
    int res = 0;
    for (ll i = 1; i * i <= t; i++) {
        if (t % i == 0) {
            if (i <= n)
                res++;

            ll b = t / i;
            if (b != i && b <= n) {
                res++;
            }
        }
    }

    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    cin >> tt;

    while (tt--) {
        sol();
    }
} 
