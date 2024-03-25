#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

int main() {
    int n;
    cin >> n;
    vi t(n);

    for(auto& x : t)
        cin >>x;

    bool f = false;
    for(int i = 0; i < n && !f; i++) {
        int j = i;
        int temp = 0;
        
        while (temp < 3) {
            j = t[j] - 1;
            temp++;
        }
        if(j == i) f = true;
    }

    cout << (f ? "YES\n" : "NO\n");

    return 0;
}
