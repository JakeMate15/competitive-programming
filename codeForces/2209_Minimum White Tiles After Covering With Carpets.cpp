#include<bits/stdc++.h>
using namespace std;

int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
    int n = floor.size();
    
    vector<vector<int>> dp(numCarpets + 1, vector<int>(n + 1, 0));
    for(int i = n - 1; i >= 0; i--){
        for(int k = 0; k <= numCarpets; ++k){
            if(k == 0){
                dp[k][i] = dp[k][i + 1] + (floor[i] == '1' ? 1 : 0);
            } else{
                int option1 = (floor[i] == '1' ? 1 : 0) + dp[k][i + 1];
                int end = min(i + carpetLen, n);
                int option2 = dp[k - 1][end];
                
                dp[k][i] = min(option1, option2);
            }
        }
    }
    
    return dp[numCarpets][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    string floor;
    int numCarpets, carpetLen;

    cin >> floor >> numCarpets >> carpetLen;

    while(t--) {
        cout << minimumWhiteTiles(floor, numCarpets, carpetLen) << "\n";
    }

    return 0;
}