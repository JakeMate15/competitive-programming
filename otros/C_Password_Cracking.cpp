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

int ask (string s) {
    cout << "? " << s << "\n";
    cout.flush();
    int res;
    cin >> res;
    if (res == -1) {
        exit(0);
    }
    return res;
}

void ans (string s) {
    cout << "! " << s << "\n";
    cout.flush();
}

void sol () {
    int n;
    cin >> n;

    int ok;
    int cnt = 0;
    string s = "0";

    while (cnt != 2) {
        ok = ask(s);
        if (ok == 1) {
            if (sz(s) == n) {
                ans(s);
                return;
            } 
            cnt = 0;
            s += "0";
        } else {
            s.back() = (cnt == 0 ? '1' : '0');
            cnt++;
        }
    }

    s.pop_back();

    string aux = "0";
    while (sz(aux) + sz(s) < n) {
        ok = ask(aux + s);

        if (ok == 0) {
            aux[0] = '1';
        }

        aux = "0" + aux;
    }

    aux[0] = (ask(aux + s) == 0 ? '1' : aux[0]);
    ans(aux + s);
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