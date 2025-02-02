#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    // #include "algoDebug.h"
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
    int n;
    
    cout << "Ingresa los vendedores\n";
    cin >> n;
    vector<ld> ventas(n);

    for (int i = 0; i < n; i++) {
        cin >> ventas[i];
        ventas[i] *= 0.09;
        ventas[i] += 200.0;

        cout << ventas[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << fixed << setprecision(10);

    int t = 1;
    // cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}