#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()

typedef long long ll;

int main () {
    int tt;
    cin >> tt;

    while (tt--) {
        string s;
        cin >> s;

        bool f = true, z = false;
        int zeros = count(all(s), '0'), cnt = 0;

        if (zeros == 0) {
            cout << "cyan\n";
            continue;
        }

        ll sum = 0;
        for (auto x: s) {

            if ((x - '0') % 2 == 0) {
                cnt++;
            }

            sum += (x - '0');
        }

        // cerr << s << " " << sum << " " << z << "\n";

        if ((sum % 3 == 0) && (cnt > 1)) {
            cout << "red\n";
        }
        else {
            cout << "cyan\n";
        }

    }

    return 0;
}