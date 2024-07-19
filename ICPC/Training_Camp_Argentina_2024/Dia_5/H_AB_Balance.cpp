#include <bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()
#define sz(a)   (int) a.size()

typedef long long ll;
typedef pair<int, int> ii;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    cin >> tt;

    while (tt--) {
        string s;
        cin >> s;

        int ab = 0, ba = 0;
        for (int i = 0; i < sz(s) - 1; i++) {
            string c = s.substr(i, 2);
            ab += (c == "ab");
            ba += (c == "ba");
        }

        // cerr << s << " " << ab << " " << ba << "\n";

        if (ab == ba) {
            cout << s << "\n";
            continue;
        }

        // cout << s.back();
        // for (int i = 0; i < sz(s) - 1; i++)
        //     cout << s[i];
        // cout << "\n";
        // rotate(s.begin(), s.end() - 1, s.end());

        if (s[0] != s.back()) {
            s[0] = s.back();
        }

        cout << s << "\n";
    }

    return 0;
}