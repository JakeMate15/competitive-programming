#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl()            cout << "\n"
typedef long long ll;

//Recordemos que a ^ a = 0, que basicamente es como invertir cada elemento si en el rango dado
//Que es lo mismo que quitar ese xor a cada grupo x0 y x1

void sol(){
    int n;
    string s;
    
    cin >> n;
    vector<int> a(n), pref(n + 1, 0);
    int x0 = 0, x1 = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i + 1] = a[i];

        if(i) {
            pref[i + 1] ^= pref[i];
        }
    }

    cin >> s;
    for(int i = 0; i < n; i++) {
        if(s[i] - '0') {
            x1 ^= a[i];
        }
        else{
            x0 ^= a[i];
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int op, l, r;
        cin >> op;

        if(op == 2) {
            cin >> l;
            if(l) {
                deb(x1);
            }
            else{
                deb(x0);
            }
        }
        else if(op == 1){
            cin >> l >> r;
            int inv = pref[r] ^ pref[l - 1];

            x0 ^= inv;
            x1 ^= inv;
        }
    }

    nl();
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