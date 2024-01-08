#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 1000 + 5;

string g[MX];
bool vis[MX][MX];
int n, m;

const int dr[] = {1,-1,0,0,1,-1,-1,1};
const int dc[] = {0,0,1,-1,1,1,-1,-1};

bool ok(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '.';
}

void dfs(int x, int y) {
    if(!ok(x, y, n, m) || vis[x][y])
        return;

    vis[x][y] = true;
    dfs(x + 1, y);
    dfs(x, y + 1);
    dfs(x - 1, y);
    dfs(x, y - 1);
}

void sol(){
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> g[i];
    }

    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && g[i][j] == '.') {
                res++;
                dfs(i, j);
            }
        }
    }
    cout << res << "\n";
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