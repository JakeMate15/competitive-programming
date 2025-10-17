#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        long long k;
        unsigned long long x;
        cin >> k >> x;

        unsigned long long S = 1ULL << (k + 1); // total cakes
        unsigned long long a = x, b = S - x;

        vector<int> ops_rev; // operations recorded backwards
        while (a != b) {
            if (a < b) {
                // last forward move was op 1 (Chocola -> Vanilla)
                ops_rev.push_back(1);
                // previous state
                b -= a;
                a <<= 1;
            } else { // a > b
                // last forward move was op 2 (Vanilla -> Chocola)
                ops_rev.push_back(2);
                a -= b;
                b <<= 1;
            }
        }

        // reverse to get the forward sequence
        reverse(ops_rev.begin(), ops_rev.end());
        cout << ops_rev.size() << "\n";
        for (size_t i = 0; i < ops_rev.size(); ++i) {
            if (i) cout << ' ';
            cout << ops_rev[i];
        }
        cout << "\n";
    }
    return 0;
}
