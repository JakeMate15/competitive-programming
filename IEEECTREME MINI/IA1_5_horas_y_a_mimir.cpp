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

// const int MX = 1E3;
const int MOD = 1E9 + 7;

inline bool pal(ll x) {
    ll original = x;
    ll rev = 0;
    
    while (x != 0) {
        ll d = x % 10;
        rev = rev * 10 + d;
        x /= 10;
    }
    
    return original == rev;
}

void sol () {
    /*
        Para este problema, considere 10^8 y no 108. 
        El numero de numeros menores a mil es 14 y son: 
            4
            9
            77
            121
            181
            313
            434
            484
            505
            545
            595
            636
            676
            818

        La idea de la solucion es obtener los cuadrados menires a MX que son sqrt(MX)
        Despues obtener la suma de prefijos, esto nos permite obtener la suma de cualcuqier subarreglo o cuadrados consecutivos en 
        tiempo constatne, solo tendiramos que saber si es palindromos

        el tiempo esperado de ejecucion es de ~ 2.5 segundos
    */

    int MX = 1E8;

    vector<ll> cuadrados;
    for (int i = 2; i * i < MX; i++) {
        cuadrados.push_back(i * i);
    }

    vector<ll> pref = cuadrados;
    for (int i = 1; i < sz(pref); i++) {
        pref[i] += pref[i - 1];
    }

    auto get = [&] (int l, int r) -> ll {
        if (l == 0)
            return pref[r];
        return pref[r] - pref[l - 1];
    };

    set<ll> ok;
    for (int tam = 1; tam <= sz(cuadrados); tam++) {
        for (int i = 0; i < sz(cuadrados) - tam; i++) {
            auto s = get(i, i + tam - 1);
            if (pal(s) && s < MX) {
                ok.insert(s);
                // cerr << 
            }
        }
    }

    ll sum = 0, cnt = 0;
    for (auto x: ok) {
        sum += x;
        cerr << x << endl;
        cnt++;
    }

    cout << sum << "\n";
    // cerr << cnt;

    // ll s = 0;
    // for (auto x: ok) {
    //     cerr << x << "\n";
    //     s += x;
    // }
    // cout << s << "\n";
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