#include <bits/stdc++.h>
#define N 2010
#define INF 1000000000

using namespace std;

int dp[N];
int n,k;

int conejos(int m){
    if(m==0 || m==1)
        return 0;
    if(dp[m] != -1)
        return dp[m];
    dp[m] = INF;
    int actual;
    for(int i=max(1,k-n+m);i<=k&&i<m;i++){
        actual = conejos(m-i)+1;
        actual = max(actual,conejos(i));
        dp[m] = min(dp[m],actual);
    }

    return dp[m];
}

int main (){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;

    if(n==1){
        cout << "0";
        return 0;
    }
    if(n==k){
        cout << "-1";
        return 0;
    }

    memset(dp,-1,sizeof(int)*N);
    cout << conejos(n) << endl;

    return 0;
}