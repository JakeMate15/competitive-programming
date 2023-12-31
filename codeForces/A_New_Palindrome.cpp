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
    set<char> dif;
    for(int i = 0; i < sz(s) / 2; i++) {
        dif.insert(s[i]);
        assert(i < sz(s) / 2);
    }

    if(sz(dif) == 1) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;
    // assert(t < 10);

    while(t--){
        sol();
    }

    return 0;
}