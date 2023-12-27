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

    vector<int> cnt(n + 1, 0);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        cnt[u]++;
        cnt[v]++;
    }

    int res = 0;
    for(int i = 1; i <= n; i++) {
        res += cnt[i] == 1;
    }

    cout << (res + 1) / 2 << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}