#include <bits/stdc++.h>
using namespace std;

long long maxCoins(long long n) {
    if(n <= 3) return 1;
    unsigned long long x = (unsigned long long)n;
    int k = 63 - __builtin_clzll(x);
    return (1LL << (k - 1));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        cout << maxCoins(n) << "\n";
    }
    return 0;
}
