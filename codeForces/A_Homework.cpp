#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include "/algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

void sol () {
    int n, m;
    string a, b, c;
    cin >> n >> a >> m >> b >> c;

    deque<char> dq(all(a));
    for (int i = 0; i < m; ++i) {
        if (c[i] == 'V') 
            dq.push_front(b[i]);
        else 
            dq.push_back(b[i]);
    }

    for (auto ch : dq) {
        cout << ch;
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}