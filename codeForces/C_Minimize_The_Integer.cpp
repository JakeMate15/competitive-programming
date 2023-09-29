#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl()            cout << "\n"
typedef long long ll;

void sol(){
    string s;
    cin >> s;

    vector<int> pares, impares;
    for(auto c: s) {
        int n = c - '0';
        if(n & 1) {
            impares.push_back(n);
        }
        else{
            pares.push_back(n);
        }
    }

    int i = 0, j = 0;
    while (i < sz(impares) && j < sz(pares)) {
        if(impares[i] < pares[j]) {
            cout << impares[i];
            i++;
        }
        else{
            cout << pares[j];
            j++;
        }
    }

    while(i < sz(impares)) {
        cout << impares[i++];
    }

    while (j < sz(pares)) {
        cout << pares[j++];
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