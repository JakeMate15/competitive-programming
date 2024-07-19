#include<bits/stdc++.h>
using namespace std;

const int dr[] = {1,-1,0,0,1,-1,-1,1};
const int dc[] = {0,0,1,-1,1,1,-1,-1};
string dir = "UDLR", diro = "DURL";

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> g(n, vector<char>(m)), ant(n, vector<char>(m, 'Z'));

    pair<int, int> inicio, fin;
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

    auto ok = [&] (int x, int y) -> bool {
        return x >= 0 && x < n && y >= 0 && y < m;
    };


    queue<pair<int, int>> q;
    q.push(inicio);
    while(!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        int x = curr.first, y = curr.second;

        for(int i = 0; i < 4; i++) {
            int nx = x + dr[i], ny = y + dc[i];
            if(!ok(nx, ny) || g[nx][ny] == '#' || ant[nx][ny] != 'Z')   
                continue;

            ant[nx][ny] = dir[i];
            q.emplace(nx, ny);
        }
    }

    if(ant[fin.first][fin.second] == 'Z') {
        cout << "NO\n";
        return 0;
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

    cout << res.size() << "\n";
    reverse(res.begin(), res.end());
    for(auto x: res) {
        cout << diro[dir.find(x)];
    }


    return 0;
}