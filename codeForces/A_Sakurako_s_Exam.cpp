#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

void sol () {
    int a, b;
    cin >> a >> b;

    vector<int> arr(a, 1);
    arr.insert(arr.end(), b, 2);

    int n = arr.size();
    int totalCombinations = 1 << n; 

    for (int i = 0; i < totalCombinations; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                sum += arr[j];
            } else {
                sum -= arr[j];
            }
        }
        if (sum == 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}