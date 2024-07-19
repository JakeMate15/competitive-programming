#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
    int tt = 1;
    // cin >> tt;

    while (tt--) {
        string ss;
        cin >> ss;

        bool f = false;
        for (int i = 0; i < 5; i++) {
            string s;
            cin >> s;

            f |= (s[0] == ss[0] || s[1] == ss[1]);
        }

        cout << (f ? "YES" : "NO") << "\n";
    }

    return 0;
}