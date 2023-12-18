#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

bool cmp(pair<char, int> a, pair<char, int> b) {
    return a.second < b.second;
}

void sol(){
    string s;
    cin >> s;

    int n = sz(s);
    vector<pair<char, int>> minus, mayus;

    for(int i = 0; i < n; i++) {
        if(s[i] == 'b') {
            if(sz(minus))
                minus.pop_back();
        }
        else if(s[i] == 'B') {
            if(sz(mayus))
                mayus.pop_back();
        }
        else if(s[i] >= 'a' && s[i] <= 'z') {
            minus.emplace_back(s[i], i);
        }
        else if(s[i] >= 'A' && s[i] <= 'Z') {
            mayus.emplace_back(s[i], i);
        }
    }

    minus.insert(minus.end(), all(mayus));
    sort(all(minus), cmp);
    for(auto x: minus) {
        cout << x.first;
    }
    nl;
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