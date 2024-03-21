#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()
#define sz(a)   (int)a.size()
typedef long long ll;

const int mod = 1e9 + 7;
const int MX = 100000 + 5;

int costos[MX], n;
string palabras[MX];
ll dp[MX][2];

ll go (int i, int invertido) {
    if (i == n)
        return 0;

    ll &mem = dp[i][invertido];
    if (mem != -1)
        return mem;

    string anterior = palabras[i - 1];
    if (invertido) 
        reverse(all(anterior));

    ll res = 1E18;
    string act = palabras[i];

    if (anterior <= act)
        res = min(res, go(i + 1, 0));

    reverse(all(act));
    if (anterior <= act)
        res = min(res, go(i + 1, 1) + costos[i]);

    return mem = res;
}

int main () {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> costos[i];
        dp[i][0] = dp[i][1] = -1;
    }

    for (int i = 0; i < n; i++) {
        cin >> palabras[i];
    }

    ll res = min(go(1, 0), go(1, 1) + costos[0]);
    cout << (res == 1E18 ? -1 : res) << "\n";

    return 0;
}