#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

void sol () {
    string s;
    cin >> s;

    int n = sz(s);
    for(int i = 0; i < n; ++i){
        int mx = s[i] - '0';
        int p = i;
        for(int j = i + 1; j <= min(i + 9, n - 1); j++){
            int curr = (s[j] - '0') - (j - i);
            if(curr > mx){
                mx = curr;
                p = j;
            }
        }
        if(p != i){
            s[p] = '0' + mx;
            char d = s[p];
            s.erase(s.begin() + p);
            s.insert(s.begin() + i, d);
        }
    }

    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}