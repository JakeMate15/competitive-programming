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
    string s, aux;
    cin >> n >> s;

    map<char, int> rep;
    for(auto x: s) {
        rep[x]++;

        if(rep[x] > n / 2 || (n & 1)) {
            cout << -1 << "\n";
            return;
        }
    }

    int res = 0;
    map<char, int> rep2;
    for(int i = 0; i * 2 < n; i++) {
        if(s[i] == s[n - i - 1]) {
            res++;
            rep2[s[i]]++;
        }
    }

    for(char c = 'a'; c <= 'z'; c++) {

    }


    cout << (res + 1) / 2 << "\n";
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