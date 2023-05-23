#include <bits/stdc++.h>

using namespace std;

int dp[2000+5][2000+5];

int cbc(int n, int k){
    
    for(int i=0; i<n+2;i++){
        dp[i][0] = 1;
    }

    for(int i=0; i<n+2;i++){
        dp[0][i] = 0;
    }   
    dp[1][1] = 1;

    for(int i=1; i<n+2;i++){
        for(int j=1; j<i+2;j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    return  dp[n][k-1]+dp[n][k];
}

int main (){
    int n,k;
    cin >> n >> k;

    if(n!=k){
        double div = cbc(n,k)*1.00/n;
    
        cout << ceil(div) << endl;
    }
    else{
        cout << "-1";
    }


    //

    return 0;
}