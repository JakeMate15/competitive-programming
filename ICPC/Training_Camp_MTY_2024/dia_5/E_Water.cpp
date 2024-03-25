#include<bits/stdc++.h>
using namespace std;

#define sz(a)   a.size()
typedef long long ll;

int main () {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        ll c;
        cin >> n >> c;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll res = 1;
        ll agua = c;

        for (int i = 0; i < n; i++) {
            agua -= a[i];
            if (agua <= 0) {
                agua = c;
                res++;
            }


        }

        cout << res << "\n";
    }
}