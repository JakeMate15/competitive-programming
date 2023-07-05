#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

#define debug(a)    cout << a << "\n"

int n, m, A[MAXN + 10];

void solve() {
    scanf("%d%d", &n, &m);

    int zero = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        if (A[i] == 0) zero++;
    }


    
    // special cases
    if (n == m) printf("Richman\n");
    else if (zero > m) printf("Impossible\n");
    else {
        m -= zero;
        // calculate the sum of prices of the first (m - zero) books
        long long sm = 0;
        int i;
        for (i = 1; m > 0; i++) {
            if (A[i] == 0) continue;
            sm += A[i];
            m--;
        }

        debug("hola");
        debug(m);
        debug(i-1);
        debug(sm);
        debug("adios");

        // calculate the minimum price of the remaining (n - m) books
        int mn = 1e9;
        for (; i <= n; i++) if (A[i] > 0) mn = min(mn, A[i]);
        // output the answer
        printf("%lld\n", sm + mn - 1);
    }
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}