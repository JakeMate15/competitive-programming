#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

vector<string> aux = {"111","110","101","100","011","010","001","000"};

int next(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return x / i;
        }
    }
    return 1; 
}


int mn(int a, int b) {
    int r = 0;
    while (a != b) {
        if (a < b) swap(a, b); 
        a = next(a);
        ++r;
    }
    return r;
}


void sol() {
    int n;
    cin >> n; 
    vector<int> A(n), B(n);

    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) cin >> B[i];

    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += mn(A[i], B[i]);
    }

    cout << res << "\n";
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