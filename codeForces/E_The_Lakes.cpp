#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int mx = 1000 + 10;

int g[mx][mx];
bool vis[mx][mx];
int n,m;

bool ok(int x, int y){
    if(x>=n || y>=m || vis[x][y] || g[x][y]<=0 || x<0 || y<0) return true;

    return false;
}

void dfs(int x, int y, int &v){
    if(ok(x,y))    return;
    
    vis[x][y] = true;
    v+=g[x][y];
    
    dfs(x+1,y,v);
    dfs(x,y+1,v);
    dfs(x-1,y,v);
    dfs(x,y-1,v);

    return;
}

void sol(){
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>g[i][j];
            vis[i][j] = false;
        }
    }

    int maxV = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && g[i][j]!=0){
                int res = 0;
                dfs(i,j,res);
                maxV = max(res,maxV);
            }
        }
    }

    cout << maxV << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t=1;
	cin>>t;
	while(t--){
		sol();
	}

	return 0;
}