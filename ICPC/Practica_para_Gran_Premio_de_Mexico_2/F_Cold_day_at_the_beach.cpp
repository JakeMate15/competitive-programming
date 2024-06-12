#include<bits/stdc++.h>
using namespace std;

#define sz(a)   (int) a.size()
#define all(a)  a.begin(), a.end()

typedef long long ll;
typedef pair<int, int> pi;

int main () {
    int n;
    cin >> n;

    int w, l, x, y;
    cin >> w >> l >> x >> y;

    vector<pi> a(n), b(n);
    for (auto &[xx, yy]: a) {
        cin >> xx >> yy;
    }
    for (auto &[xx, yy]: b) {
        cin >> xx >> yy;
    }

    auto d = [&] (int xx, int yy) -> ll {
        return (x - xx) * (x - xx) + (y - yy) * (y -yy);
    };
 
    sort(all(a), [&] (pi a, pi b) {
        return d(a.first, a.second) < d(b.first, b.second);
    });
    sort(all(b), [&] (pi a, pi b) {
        return d(a.first, a.second) < d(b.first, b.second);
    });

    int res = 0;
    if (d(a[0].first, a[0].second) < d(b[0].first, b[0].second)) {
        for (int i = 0; i < n; i++) {
            if (d(a[i].first, a[i].second) >= d(b[0].first, b[0].second))
                break;
            res++;
        }
        cout << "A " << res;
    }
    else {
        for (int i = 0; i < n; i++) {
            if (d(b[i].first, b[i].second) >= d(a[0].first, a[0].second))
                break;
            res++;
        }
        cout << "R " << res;
    }
}