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
    cout << "Elige una opción:\n";
    cout << "1. Caja\n";
    cout << "2. Óvalo\n";
    cout << "3. Flecha\n";
    cout << "Cualquier otra cosa: Diamante\n";

    string op;
    cin >> op;

    int n = 5, m = 7;
    if (op == "1") {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << ((i == 0 || i == n - 1 || j == 0 || j == m - 1) ? '*' : ' ');
            }
            cout << "\n";
        }
    } else if (op == "2") {
        n = 10, m = 20;

        double a = n / 2.0;
        double b = m / 2.0;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                double eq = pow((i - a) / a, 2) + pow((j - b) / b, 2);
                cout << (eq <= 1.0 ? '\'' : ' ');
            }
            cout << "\n";
        }
    } else if (op == "3") {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n - i; j++)
                cout << ' ';
            for(int j = 0; j < (2*i +1); j++)
                cout << '"';
            cout << "\n";
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                cout << ' ';
            cout << '"' << '\n';
        }
    } else {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n - i; j++)
                cout << ' ';
            for(int j = 0; j < (2 * i +1); j++)
                cout << "+";
            cout << "\n";
        }
        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j < n - i; j++)
                cout << ' ';
            for(int j = 0; j < (2 * i + 1); j++)
                cout << "+";
            cout << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    // cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}