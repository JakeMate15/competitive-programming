#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

ll ask (ll l, ll r) {
    cout << "xor " << l << " " << r << "\n";
    cout.flush();
    ll ans;
    cin >> ans;
    if (ans == -1) {
        exit(0);
    }
    return ans;
}

void sol () {
    ll n;
    cin >> n;

    ll tot = ask(1, n);

    vector<ll> pos;
    queue<ii> q;
    q.push({1, n});

    while (!q.empty() && sz(pos) < 2) {
        ll l = q.front().first;
        ll r = q.front().second;
        q.pop();

        if (l == r) {
            pos.push_back(l);
            continue;
        }

        ll mid = (l + r) / 2;
        ll s = ask(l, mid);

        if (s == 0) {
            q.push({mid + 1, r});
        } else {
            q.push({l, mid});
        }
    }

    ll a = pos[0];
    ll b = pos[1];
    ll c = tot ^ a ^ b;

    debug(pos);

    cout << "ans " << a << " " << b << " " << c << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}