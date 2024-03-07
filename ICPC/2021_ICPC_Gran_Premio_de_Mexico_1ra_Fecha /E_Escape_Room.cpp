#include<bits/stdc++.h>
using namespace std;

string DIR = "RLDU";
const int dr[] = {1, -1, 0,  0};
const int dc[] = {0,  0, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> g(n, vector<char>(m));
    pair<int, int> inicio = {0, 0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'E') {
                inicio = {i, j};
            }
        }
    }

    auto ok = [&](int x, int y) -> bool {
        return x >= 0 && x < n && y >= 0 && y < m;
    };

    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));

    dist[inicio.first][inicio.second] = 0;
    q.push(inicio);
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int x = curr.first, y = curr.second;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dc[dir], ny = y + dr[dir];
            if (ok(nx, ny) && g[nx][ny] == '.' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.emplace(nx, ny);
            }
        }
    }

    auto get = [&](char c) -> int {
        if (c == 'L')   return 0;
        if (c == 'D')   return 1;
        if (c == 'R')   return 2;
        return 3;
    };

    int qu;
    cin >> qu;
    while (qu--) {
        int x, y;
        cin >> x >> y;
        x--, y--;

        char nc = g[x][y];
        if (nc == '#') {
            cout << "W\n";
        }
        else if (nc == 'X') {
            cout << "X\n";
        }
        else if (nc == 'E') {
            cout << "E\n";
        }
        else if (dist[x][y] == -1) {
            cout << "?\n";
        }
        else {
            vector<pair<int, char>> res;
            for (int i = 0; i < 4; i++) {
                int nx = x + dc[i], ny = y + dr[i];
                if (ok(nx, ny) && dist[nx][ny] != -1 && (g[nx][ny] == '.' || g[nx][ny] == 'E')) {
                    res.emplace_back(dist[nx][ny], DIR[i]);
                }
            }

            sort(res.begin(), res.end(), [&](pair<int, char> a, pair<int, char> b){
                if (a.first == b.first) {
                    return get(a.second) < get(b.second);
                }
                return a.first < b.first;
            });
            
            cout << res[0].second << "\n";
        }
    }

    return 0;
}