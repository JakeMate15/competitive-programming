#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

const int dr[] = {1,-1,0,0,1,-1,-1,1};
const int dc[] = {0,0,1,-1,1,1,-1,-1};
string dir = "UDLR", diro = "DURL";

bool ok(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void sol(){
    int n, m;
    cin >> n >> m;

    vector<vector<char>> g(n, vector<char>(m)), ant(n, vector<char>(m, 'Z'));

    ii inicio, fin;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> g[i][j];
            if(g[i][j] == 'A') {
                inicio = {i, j};
            }
            if(g[i][j] == 'B') {
                fin = {i, j};
            }
        }
    }


    queue<ii> q;
    q.push(inicio);
    while(!q.empty()) {
        ii curr = q.front();
        q.pop();
        int x = curr.first, y = curr.second;

        for(int i = 0; i < 4; i++) {
            int nx = x + dr[i], ny = y + dc[i];
            if(!ok(nx, ny, n, m) || g[nx][ny] == '#' || ant[nx][ny] != 'Z')   
                continue;

            ant[nx][ny] = dir[i];
            q.emplace(nx, ny);
        }
    }

    if(ant[fin.first][fin.second] == 'Z') {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    string res = "";
    while(fin != inicio) {
        int x = fin.first, y = fin.second;
        res += ant[x][y];
        
        int i = 0;
        i = (res.back() == 'U' ? 1 : i);
        i = (res.back() == 'L' ? 3 : i);
        i = (res.back() == 'R' ? 2 : i);

        fin = {x + dr[i], y + dc[i]};
    }

    cout << sz(res) << "\n";
    reverse(all(res));
    for(auto x: res) {
        cout << diro[dir.find(x)];
    }
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