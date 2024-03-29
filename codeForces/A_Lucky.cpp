#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol(){
    string s;
    cin >> s;

    int l = 0, r = 0;
    for(int i = 0; i < 6; i++) {
        l += (i < 3 ? s[i] - '0' : 0);
        r += (i >= 3 ? s[i] - '0' : 0);
    }
    cout << (l == r ? "YES" : "NO") << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}