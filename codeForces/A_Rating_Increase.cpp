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
    // cerr << "=============\n";
    string s;
    cin >> s;

    for(int i = 0; i < sz(s) - 1; i++) {
        string a = s.substr(0, i + 1);
        string b = s.substr(i + 1);
        // cerr << a << " " << b << "\n";

        if(b[0] == '0' || a == b) {
            continue;
        }
        
        int aa = stoi(a), bb = stoi(b);
        if(bb > aa) {
            cout << aa << " " << bb << "\n";
            return;
        }
    }

    cout << -1 << "\n";
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