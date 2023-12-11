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
    string s;
    cin >> s;

    int i, n = sz(s);
    for(i = n - 1; i >= 0; i--) {
        if(s[i] != '0')
            break;
    }
    
    if(i == n - 1)
        i--;

    for(; i >= 0; i--) {
        if(s[i] != '0')
            break;
    }

    if(isdigit(s[i]) && s[i + 1] == '0')
        i--;

    for(int j = 0; j <= i; j++)
        cout << s[j];
    
    nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    cin>>t;

    while(t--){
        sol();
    }

    return 0;
}