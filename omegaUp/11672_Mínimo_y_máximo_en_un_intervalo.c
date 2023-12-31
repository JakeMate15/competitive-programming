#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MX 100005

typedef struct {
    int first;
    int second;
} Pair;

Pair aux(Pair a, Pair b) {
    Pair result;
    result.first = (a.first < b.first) ? a.first : b.first;
    result.second = (a.second > b.second) ? a.second : b.second;
    return result;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    Pair st[MX];
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        st[n + i].first = x;
        st[n + i].second = x;
    }
    for (int i = n - 1; i > 0; i--) {
        st[i] = aux(st[i << 1], st[i << 1 | 1]);
    }

    while (q--) {
        char i;
        int l, r;
        scanf(" %c %d %d", &i, &l, &r);

        if (i == 'A') {
            l--;
            st[l += n].first = r;
            st[l].second = r;
            while (l >>= 1)
                st[l] = aux(st[l << 1], st[l << 1 | 1]);
        } else {
            r--, l--;
            Pair res;
            res.first = INT_MAX;
            res.second = -1;
            for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
                if (l & 1) res = aux(st[l++], res);
                if (!(r & 1)) res = aux(st[r--], res);
            }
            printf("%d %d\n", res.first, res.second);
        }
    }

    return 0;
}
