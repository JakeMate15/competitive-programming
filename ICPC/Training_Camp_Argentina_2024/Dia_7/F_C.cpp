#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define all(v)          v.begin(), v.end()
#define rall(v)         v.rbegin(), v.rend()
#define sz(a)           (int)a.size()

void sol() {
    ll a, b, n;
    cin >> a >> b >> n;

    int res = 0;
    while(1) {
        if(a < b)
            swap(a, b);
        if(a > n)
            break;
        b += a;
        res++;
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}
