//https://cses.fi/problemset/task/1635
//https://cses.fi/problemset/task/1635
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,objetivo;
    int mod = 1e9+7;
    cin>>n>>objetivo;
    vector<int>monedas(n);
    for(int i=0;i<n;i++)    cin>>monedas[i];
    
    int dp[objetivo+1];
    memset(dp,0,sizeof(dp));
 
    for(int i=1;i<=objetivo;i++){
        for(int c: monedas){
            if(i-c>0){
                (dp[i] += dp[i-c])%=mod;
            }
            else if(i-c==0){
                (dp[i]+=1)%=mod;
            }
        }
    }
    cout << dp[objetivo] << endl;
 
    return 0;
}