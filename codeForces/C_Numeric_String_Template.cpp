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

bool ok(const vector<int>& a, const string& s) {
    if (sz(a) != sz(s)) 
        return false;
    
    unordered_map<int, char> mapAtoS;
    unordered_map<char, int> mapStoA;
    
    for (int i = 0; i < sz(a); ++i) {
        int num = a[i];
        char ch = s[i];
        
        if (mapAtoS.find(num) != mapAtoS.end()) {
            if (mapAtoS[num] != ch) return false;
        } else {
            mapAtoS[num] = ch;
        }
        
        if (mapStoA.find(ch) != mapStoA.end()) {
            if (mapStoA[ch] != num) return false;
        } else {
            mapStoA[ch] = num;
        }
    }
    
    return true;
}

void sol () {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;

        if (ok(a, s)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}