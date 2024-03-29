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

    s += "9";
    string res = s.substr(0, 1);
    char ant = s[0];
    for(int i = 1; i < n; i++) {
        if(s[i] == ant) {
            i++;
            char aux = s[i];
            res += s[i];
            ant = s[i];
        }
    }
    cout << res.substr(0, sz(res) - 1) << "\n";
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