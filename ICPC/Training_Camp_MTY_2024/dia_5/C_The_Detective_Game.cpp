#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol() {
    int n;
    cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int xx;
            cin >> xx;
            a[xx]++;
        }
    }

    vector<int> res;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > n / 2) {
            res.push_back(i);
        }
    }

    cout << sz(res) << endl;
    sort(all(res));
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}