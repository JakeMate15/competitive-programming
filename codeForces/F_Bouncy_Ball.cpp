#include<bits/stdc++.h>
using namespace std;
 
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

string dir;
int n, m, xi, yi, xf, yf;
vector<vector<int>> g;

// map<string, int> dirs = {{"DR", 0}, {"DL", 1}, {"UL", 3}, {"UR", 2}};
// map<string, string> oEs = {{"DR", "UL"}, {"DL", "UR"}, {"UL", "DR"}, {"UR", "DL"}};

// map<string, string> oX = {{"DR", "UR"}, {"DL", "UL"}, {"UL", "DL"}, {"UR", "DR"}};
// map<string, string> oY = {{"DR", "DL"}, {"DL", "DR"}, {"UL", "UR"}, {"UR", "UL"}};

// int dx[] = {1, 1, -1, -1};
// int dy[] = {1, -1, 1, -1};

// bool ok(int i, int j) {
//     return i >= 0 && i < n && j >= 0 && j < m;
// }

// bool esquina(int i, int j) {
//     if(i == 0 && j == 0)
//         return true;
//     if(i == 0 && j == m - 1)
//         return true;
//     if(i == n - 1 && j == 0)
//         return true;
//     if(i == n - 1 && j == m - 1)
//         return true;
//     return false;
// }

// int dfs(int i, int j, string dir, int pasos) {
//     //cerr << i << " " << j << "\n";
//     if(!ok(i, j)) {
//         return -1;
//     }

//     // EStamos en el punto
//     if(i == (xf - 1) && j == (yf - 1)) {
//         // cerr << "llegue\n";
//         return pasos;
//     }   

//     int d = dirs[dir];

//     // Ya estamos en un borde o esquina
//     if(!ok(i + dx[d], j + dy[d])) {
//         // cerr << "pared \n";
//         pasos++;
//         if(esquina(i, j)) {
//             if(g[i][j] > 5) {
//                 // cerr << "esquina\n";
//                 return -1;
//             }
//             dir = oEs[dir];
//         } 
//         else if(i == 0 || i == n - 1) {
//             dir = oX[dir];
//         }
//         else {
//             dir = oY[dir];
//         }
        
//         d = dirs[dir];
//     }
//     d = dirs[dir];
//     g[i][j]++;

//     return dfs(i + dx[d], j + dy[d], dir, pasos);
// }


void sol(){
    //cerr << "===============\n";
    int n, m, i1, j1, i2, j2;
    string d;
    cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> d;
    
    int dx = 1;
    int dy = 1;
    if (d[0] == 'U') {
        dx = -1;
    }
    if (d[1] == 'L') {
        dy = -1;
    }
    
    int contador = 0;
    int res = 0;
    while (contador < 4 * n * m) {
        if (i1 == i2 && j1 == j2) {
            cout << res << "\n";
            return;
        }
        contador++;
        bool rebote = false;
        if (i1 + dx < 1 || i1 + dx > n) {
            rebote = true;
            dx *= -1;
        }
        if (j1 + dy < 1 || j1 + dy > m) {
            rebote = true;
            dy *= -1;
        }
        res += rebote;
        i1 += dx;
        j1 += dy;
    }
    cout << -1 << "\n";

}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}