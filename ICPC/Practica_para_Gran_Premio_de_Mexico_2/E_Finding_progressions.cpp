#include<bits/stdc++.h> // Incluye todas las bibliotecas estándar de C++
using namespace std;

// Macros para simplificar el código
#define vin(v) for(auto &i:(v))cin>>i
#define allr(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define vvi vector<vector<int>>
#define vi vector<int>
#define int long long

// Variables globales
int a, s, L, R;

// Función que calcula la suma desde st hasta fn
int sum_n_st_fn(int n, int st, int fn) {
    if (fn > R) {
        return s + 1;
    }
    return (n * (st + fn)) / 2;
}

// Función que verifica una condición
bool check(int st, int d) {
    if (d == 0) {
        return st == s && st == a;
    }
    int l = 2, r = 2e5, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        int tsum = sum_n_st_fn(mid, st, st + (mid - 1) * d);
        if (tsum == s) {
            return st + (mid - 1) * d >= a;
        } else if (tsum > s) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return false;
}

// Función principal del programa
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> s >> L >> R;
    int cnt = 0;
    if (a == s) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = L; i < a; i++) {
        int x = a - i;
        for (int j = 1; j * j <= x; j++) {
            if (x % j == 0) {
                cnt += check(i, j);
                if (j * j != x) {
                    cnt += check(i, x / j);
                }
            }
        }
    }
    for (int i = 0; i <= R - a; i++) {
        cnt += check(a, i);
    }
    cout << cnt << endl;
}
