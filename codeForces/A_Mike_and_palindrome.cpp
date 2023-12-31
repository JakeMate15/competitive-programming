#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

bool palindromo(string s) {
    string aux = s;
    reverse(all(aux));
    return aux == s;
}

void sol(){
    string s;
    cin >> s;

    for(int i = 0; i < sz(s); i++) {
        for(char c = 'a'; c <= 'z'; c++) {
            string aux = s;

            if(c == aux[i]) {
                continue;
            }

            aux[i] = c;

            if(palindromo(aux)) {
                cout << "YES\n";
                return;
            }
        }
    }
    
    cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}