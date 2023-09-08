#include<bits/stdc++.h>
using namespace std;

const int INF = 1e6+5;
 
int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int noC,amount;
    cin>>noC>>amount;

    vector<int> coins(noC);
    for(int i=0; i<noC; i++){
        cin>>coins[i];
    }
 
    vector<int> dp(amount+1);
    dp[0] = 0;
    for(int i=1; i<=amount;i++){
        dp[i] = INF;
        for(auto c: coins){
            if(i-c>=0){
                dp[i] = min(dp[i],dp[i-c]+1);
            }
        }
        
    }
    
    dp[amount]!=1e6+5?cout<<dp[amount]<<endl:cout<<-1<<endl;
    return 0;
}