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
    vector<string> a(3);
    for(auto &x: a) {
        cin >> x;
    }

    bool aa = false, bb = false, cc = false;
    for(int i = 0; i < 3; i++) {
        // cerr << a[i] << "\n";
        aa = false, bb = false, cc = false;
        for(int j = 0; j < 3; j++) {
            aa |= (a[i][j] == 'A');
            bb |= (a[i][j] == 'B');
            cc |= (a[i][j] == 'C');
        }
        // cerr << aa << " " << bb << " " << cc << "\n";

        if(!aa) {
            cout << "A\n";
            return;
        }
        else if(!bb) {
            cout << "B\n";
            return;
        }
        else if(!cc) {
            cout << "C\n";
            return;
        }
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