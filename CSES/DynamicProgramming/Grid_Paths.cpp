//https://cses.fi/problemset/task/1638
#include<bits/stdc++.h>
using namespace std;
 
char grid[1000][1000];
bool vis[1000][1000];
int dp[1000][1000];
const int mod = 1e9+7;
int n;
 
bool valid(int i, int j){
    return i<n && j<n && grid[i][j]=='.';
}
 
void dfs(int x, int y){
    if(!valid(x,y)) return;
    if(vis[x][y])   return;
 
    vis[x][y] = true;
    //if(x+y!=0)  dp[x][y]+=dp[aX][aY];
    dfs(x+1,y);
    dfs(x,y+1);
}
 
int main(){
    cin>>n;
    memset(dp,0,sizeof(dp));
    memset(vis,false,sizeof(vis));
 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
 
    if(grid[0][0] == '*'){
        cout << 0 << endl;
        return 0;
    }
 
    dfs(0,0);
    
 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] != '*'){
                if(i+j==0){dp[0][0] = 1;}
                else if(i==0){
                    (dp[i][j] += dp[i][j-1])%=mod;
                }
                else if(j==0){
                    (dp[i][j] += dp[i-1][j])%=mod;
                }
                else{
                    (dp[i][j] += dp[i][j-1])%=mod;
                    (dp[i][j] += dp[i-1][j])%=mod;
                }
            }
        }
    }
 
    /* 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j] << " ";
        }
        cout << endl;
    }*/
 
    cout << dp[n-1][n-1] << endl;
}