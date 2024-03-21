#include <iostream>
#include <vector>

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;

const int MX = 1E5 + 5;
int precio[1001], pags[1001], n, dinero;
int dp[1001][MX];
 
int go(int dinero, int i) {
    if(i >= n || dinero <= 0)
        return 0;
    
    int &a = dp[i][dinero];
    if(a != 0)
        return a;
 
    if(dinero < precio[i])
        return a = go(dinero, i + 1);
 
    return a = max(go(dinero, i + 1), go(dinero - precio[i], i + 1) + pags[i]);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n >> dinero;
 
    for(int i = 0; i < n; i++) {
        cin >> precio[i];
    }
 
    for(int i = 0; i < n; i++) {
        cin >> pags[i];
    }
 
    cout << go(dinero, 0);
 
    return 0;
}