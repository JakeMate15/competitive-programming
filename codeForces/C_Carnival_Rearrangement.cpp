#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(auto &x:a) {
            cin>>x;
        }

        vector<int> p(n + 1 ,0);
        for(int i = 1; i <= n; i++) {
            p[i] = p[i - 1] + (a[i - 1] == 1 ? 1 : 0);
        }

        int t1 = p[n];
        int t2 = n - t1;
        int res = min(t1, t2);
        for(int k = 0; k <= n; k++){
            int c1 = (k - p[k]) + (t1 - p[k]);
            int c2 = p[k] + (t2 - (k - p[k]));
            res = min(res, min(c1, c2));
        }
        cout << res << " ";
    }

    return 0;
}