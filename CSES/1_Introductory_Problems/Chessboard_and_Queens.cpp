#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl()            cout << "\n"
typedef long long ll;

char g[8][8];
int res = 0;
bool d1[15], d2[15], fila[7];

void dfs(int j) {
    if(j == 8) {
        res++;
        return;
    }

    for(int i = 0; i < 8; i++) {
        if(g[i][j] == '*' || fila[i] || d1[i + j] || d2[i - j + 7]) {
            continue;
        }

        fila[i] = d1[i + j] = d2[i - j + 7] = 1;

        dfs(j+1);

        fila[i] = d1[i + j] = d2[i - j + 7] = 0;

    }
}

void sol(){
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cin >> g[i][j];
        }
    }

    dfs(0);

    debln(res);

}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    //cin>>t;
    while(t--){
        sol();
    }

    return 0;
}