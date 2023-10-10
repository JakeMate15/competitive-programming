#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl()            cout << "\n"
typedef long long ll;

void sol(){
    int n;
    string s;
    cin >> n >> s;

    int cambios = 0;
    for(int i = 0; i < n / 2; i ++) {
        if(s[i] != s[n - 1 - i]) {
            cambios++;
        }
    }

    for(int i = 0; i <= n; i++) {
        if(i < cambios || i > n - cambios) {
            cout << 0;
        }
        else if(n % 2 == 0 && i % 2 != cambios % 2) {
            cout << 0;
        }
        else{
            cout << 1;
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