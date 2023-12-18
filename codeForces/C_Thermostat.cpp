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
    int l, r, x, a ,b;
    cin >> l >> r >> x >> a >> b;

    if(a == b) {
        cout << 0 << "\n";
    }
    else if(abs(a - b) >= x) {
        cout << 1 << "\n";
    }
    else if((abs(a - l) >= x && abs(l - b) >= x) || (abs(a - r) >= x && abs(r - b) >= x)) {
        cout << 2 << "\n";
    }
    else if(abs(a - r) >= x && abs(r - l) >= x && abs(l - b) >= x) {
        cout << 3 << "\n";
    }
    else if(abs(a - l) >= x && abs(l - r) >= x && abs(r - b) >= x) {
        cout << 3 << "\n";
    }
    else{
        cout << -1 << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    cin     >> t;

    while(t--){
        sol();
    }

    return 0;
}