#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol(){
    int n;
    cin >> n;

    vector<ll> a(n + 1), p(n + 1), s(n + 2, 0);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }

    for(int i = n; i >= 1; i--) {
        s[i] = s[i + 1] + a[i];
    }

    int i = 1, j = n, res = INT_MAX, mn = INT_MAX;
    while(i < j) {
        int dif = abs(p[i] - s[j]);
        if(dif < mn) {
            res = i;
            mn = dif;
        }

        i++, j--;
    }

    cout << res << "\n";
    cout << p[res] << " " << s[n - res + 1] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}