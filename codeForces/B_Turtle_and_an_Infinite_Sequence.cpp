#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        cerr << "================================ \n";
        int n, m;
        cin >> n >> m;

        if (m == 0) {
            cout << n << "\n";
            continue;
        }

        cerr << n << " " << m << "\n";
        cerr << bitset<31>(n).to_string() << "\n";
        int msb = (n == 0 ? 0 : log2(n));

        for (int i = 0; i < 5; i++) {
            ll a = (1 << msb) | (1 << i);
            ll b = INT_MAX >> (31 - msb);

            cerr << "------------------------------------\n";
            cerr << i << "\n";
            cerr << bitset<31>(a).to_string() << "\n";
            cerr << bitset<31>(b).to_string() << "\n";
            cerr << (a - n) << " " << (n - b) << "\n";
            
            ll mn = min(a - n, abs(n - b));
            n |= (mn <= m ? (1 << i) : 0);
        }   

        cout << n << "\n";
        cerr << "\n\n";
    }

    return 0;
}