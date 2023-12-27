#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

bool ok(string s) {
    for(int i = 0; i < sz(s) - 1; i++) {
        if(s[i] == s[i + 1]) {
            return false;
        }
    }
    return true;
}

void sol(){
    int n1, n2;
    cin >> n1 >> n2;
    string a, b;
    cin >> a >> b;

    if(ok(a)) {
        cout << "Yes\n";
    }
    else if(!ok(b)) {
        cout << "No\n";
    }
    else {
        string c = "";
        c += a[0];
        for(int i = 1; i < n1; i++) {
            if(a[i] == a[i - 1]) {
                c += b;
            }
            c += a[i];
        }

        // cerr << c << "\n";
        cout << (ok(c) ? "Yes" : "No") << "\n";
    }
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