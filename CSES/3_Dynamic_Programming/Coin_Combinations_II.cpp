#include<bits/stdc++.h>
using namespace std;

const int INF = 1e6+5;
const int mod = 1e9+7;
 
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,sum;
    cin>>n>>sum;

    vector<int> monedas(n);
    int dp[n+5];

    for(int i=0; i<n; i++){
        cin>>monedas[i];
    }

    dp[0] = 0;
    for(int i=1; i<=n; i++){
        dp[i] = 0;
        for(auto c: monedas){
            
        }
    }

    cout << dp[n] << "\n";


    return 0;
}