#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

/*

0101110001
*/

void sol(){
    string s;
    cin >> s;
    
    int n = sz(s), uno = count(all(s), '1'), c = count(all(s), '0');
    if(uno == c) {
        cout << 0 << "\n";
    }
    else if(uno == n || c == n) {
        cout << n << "\n";
    }
    else {
        int i = 0;

        for(; i < n; i++) {
            if(s[i] == '1') {
                if(c)
                    c--;
                else
                    break;
            }
            else {
                if(uno) {
                    uno--;
                }
                else {
                    break;
                }
            }
        }

        cout << n - i << "\n";
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