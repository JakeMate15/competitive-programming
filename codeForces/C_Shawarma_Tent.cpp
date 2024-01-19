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
    int n, sx, sy;
    cin >> n >> sx >> sy;
    int u = 0, d = 0, l = 0, r = 0;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (y > sy)
            ++u;
        if (y < sy)
            ++d;
        if (x > sx)
            ++r;
        if (x < sx)
            ++l;
    }

    int ans = max(u, max(d, max(l, r)));
    cout << ans << "\n";
    
    if (u == ans) {
        ++sy;
    } else if (d == ans) {
        --sy;
    } else if (l == ans) {
        --sx;
    } else {
        ++sx;
    }
    cout << sx << " " << sy << "\n";
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