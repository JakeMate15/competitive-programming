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

    int x = s[0] - 'a', y = s[1] - '0';
    cerr << x << " " << y << "\n";
    
    char a;
    for(int i = 0; i < 8; i++) {
        a = 'a' + i;
        if(a != s[0])
            cout << a << y << "\n";
    }

    for(int i = 1; i <= 8; i++) {
        if(i != y)
            cout << s[0] << i << "\n";
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