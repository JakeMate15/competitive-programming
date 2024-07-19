#include<bits/stdc++.h>
using namespace std;

#define all(v)  v.begin(), v.end()
#define sz(a)   (int)a.size()

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> ii;
typedef vector<vector<int>> vvi;

const int maxn = 1005;
int a[maxn][maxn];

ll gauss (ll x){
    return 1LL * x * (x + 1) / 2;
}

struct info {
    int u, d, t;
    int l;
    
    bool operator==(const info &b) const {
        return ((b.u == u) && (b.d == d) && (b.t == t) && (b.l == l));
    }
    bool operator!=(const info &b) const{
        return !(*this == b);
    }
};

info b[maxn][maxn];

void sol() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxn; j++) 
            a[i][j] = -1;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char c;
            cin >> c;
            a[i][j] = (c - 'a');
        }
    }

    for(int i = 1; i <= n; i++){
        b[i][0].l = -1;
    }

    ll ans = 0LL;
    for(int i = 2; i < n; i++){
        int w = 0;
        for(int j = 1; j <= m; j++){
            if(a[i][j] == a[i - 1][j]){
                b[i][j].l = -1;
                if(w) {
                    ans += gauss(w);
                }
                w = 0;
                continue;
            }
            //saco mi info
            int x = a[i][j];
            int l = 0;
            int idx = i;
            while(idx <= n && a[idx][j] == x){
                l++;
                idx++;
            }
            if(i - l < 1 || i + l + l - 1 > n){
                //no se puede
                b[i][j].l = -1;
                if(w){
                    ans += gauss(w);
                }
                w = 0;
                continue;
            }

            x = a[i - l][j];
            idx = i - l;
            int c1 = 0;
            while(idx < i && a[idx][j] == x){
                c1++;
                idx++;
            }
            x = a[i + l][j];
            idx = i + l;
            int c2 = 0;
            while(c2 < l && idx <= n && a[idx][j] == x){
                idx++;
                c2++;
            }

            if(c1 == l && c2 == l){
                //si se pudo la info
                // cerr << "se pudo info en " << i << " " << j << endl;
                int uno = a[i - l][j], dos = a[i][j], tres = a[i + l][j];
                b[i][j].l = l;
                b[i][j].u = uno;
                b[i][j].d = dos;
                b[i][j].t = tres;
                // cerr << "l " << l << " u " << uno << " d " << dos << " t " << tres << endl;
                if(b[i][j-1].l == -1){
                    //la pasada no tenia
                    // cerr << "pasada no tenia\n";
                    w = 1;
                }
                else{
                    if(b[i][j - 1] != b[i][j]){
                        // cerr << " no es igual a la pasada\n";
                        // no es igual a la pasada
                        if(w) {
                            ans += gauss(w);
                        }
                        w = 1;
                    }
                    else{
                        // cerr << "expando\n";
                        w++;
                    }
                }
            }
            else{
                //no se pudo
                b[i][j].l = -1;
                if(w){
                    ans += gauss(w);
                }
                w = 0;
            }
        }
        ans += gauss(w);
    }

    cout << ans << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);

    while(t--) {
        sol();
    }

    return 0;
}