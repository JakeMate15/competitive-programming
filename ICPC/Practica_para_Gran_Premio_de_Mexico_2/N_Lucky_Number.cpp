#include<bits/stdc++.h>
using namespace std;

#define sz(a)   (int) a.size()
#define all(a)  a.begin(), a.end()

typedef long long ll;
typedef pair<int, int> pi;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(5);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        a[x % 5]++;
    }

    int res = a[0], mn = min(a[1], a[4]);
    a[1] -= mn, a[4] -= mn;
    res += mn;

    mn = min(a[2], a[3]);
    a[2] -= mn, a[3] -= mn;
    res += mn;

    function<int(int, int, int)> get = [&] (int a, int b, int op) -> int {
        if (op <= 1) {
            int mn = min(a, b / 2);
            int r1 = get(a - mn, b - mn * 2, op + 1) + mn;
            mn = min(a / 3, b);
            int r2 = get(a - mn * 3, b - mn, op + 1) + mn;
            return max(r1, r2);
        }
        
        return a / 5 + b / 5;
    };

    res += max ({
        get(a[2], a[4], 0),
        get(a[1], a[2], 0),
        get(a[3], a[1], 0),
        get(a[4], a[3], 0)
    });

    cout << res << "\n";

    return 0;
}