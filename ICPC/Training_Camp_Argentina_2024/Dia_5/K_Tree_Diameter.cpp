#include <bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()
#define sz(a)   (int) a.size()

typedef long long ll;
typedef pair<int, int> ii;

set<int> a, b;
int lo, hi, mid, dist, d2, d3;

void ask () {
    // cout << "Pregunta normal\n";

    a.clear();
    for (int i = max(2, lo); i <= mid; i++)
        a.insert(i);

    
    cout << 1 << " " << sz(a) << " " << 1 << " ";
    for (auto x: a)
        cout << x << " ";
    cout << "\n";
    cin >> d2;

    // cout << "La nueva dist es " << d2 << "\n";
    // cout << "\n\n\n";
}

void sol () {
    int n;
    cin >> n;

    // a.insert(1);
    // for (int i = 2; i <= n; i++) {
    //     b.insert(i);
    // }

    // cout << "Pregunta incial\n";

    cout << 1 << " " << n - 1 << " " << 1 << " ";
    for (int i = 2; i <= n; i++) {
        cout << i << " \n"[i == n];
    }
    cin >> dist;

    // cout << "La dist es " << dist << "\n\n";

    lo = 1, hi = n + 1;
    while (lo + 1 < hi) {
        mid = (lo + hi) / 2;

        ask();
    
        if (d2 < dist)
            lo = mid;
        else
            hi = mid;

    }

    // cout << "pregunta final\n";

    hi = min(hi, n);
    cout << 1 << " " << n - 1 << " " << min(hi, n) << " ";
    for (int i = 1; i <= n; i++) {
        if (i == hi)
            continue;
        cout << i << " ";
    }
    cout << "\n";
    cin >> d3;

    // cout << "\n\nResultado\n";
    cout << "-1 " << d3 << "\n";
}

int main () {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int tt = 1;
    cin >> tt;

    while (tt--) {
        sol();
    }

    return 0;
}