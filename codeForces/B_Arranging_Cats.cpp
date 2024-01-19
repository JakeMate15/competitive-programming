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
    cin >> n;

    string s, s1;
    cin >> s >> s1;
    
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != s1[i]) {
            if (s[i] == '0') {
                a++;
            } else {
                b++;
            }
        }
    }

    cout << max(a, b) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}