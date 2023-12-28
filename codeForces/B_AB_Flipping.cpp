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
    int n;
    string s;
    cin >> n >> s;

    bool a = false, b = false;
    int tam = 0, res = 0;
    for(auto x: s) {
        if(x == 'A') {
            if(b) {
                res += tam - 1;
                tam = 1;
                b = false;
            }
            else {
                tam++;
            }
            a = true;
        }
        else {
            if(a) {
                b = true;
                tam++;
            }
        }
    }
    if(b && a) {
        res += tam - 1;
    }

    cout << res << "\n";
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