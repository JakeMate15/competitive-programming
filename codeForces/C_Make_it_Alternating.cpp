#include<bits/stdc++.h>
using namespace std;
 
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl()            cout << "\n"
 
typedef long long ll;
const int mod = 998244353;
const int mx = 2e5 + 5;

void sol(){
    string s;
    cin >> s;

    int n = sz(s);
    ll mn = 0, diff = 1, tam = 1;

    for(int i = 0; i < n; i++) {
        tam = 1;
        while(i < n && s[i] == s[i + 1]){
            i++;
            tam++;
        }
        mn += tam - 1;
        diff *= tam;
        diff %= mod;
    }

    //De cuantas formas podemos borrar la cantidad necesaria
    //seleccionando cada elemento del bloque formado
    for(int i = 1; i <= mn; i++) {
        diff *= i;
        diff %= mod;
    }

    deb(mn);debln(diff);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    cin>>t;
    while(t--){
        sol();
    }

    return 0;
}