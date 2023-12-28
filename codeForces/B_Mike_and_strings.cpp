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

    map<string, pair<int, int>> mp;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        set<string> rep;
        for(int j = 0; j < sz(s); j++) {
            string aux = s;
            rotate(aux.begin(), aux.begin() + j, aux.end());
            
            if(rep.count(aux)) {
                continue;
            }
            
            rep.insert(aux);
            mp[aux].first++;
            mp[aux].second += j;
        }
    }

    int res = INT_MAX;
    for(auto [s, m]: mp) {
        if(m.first == n) {
            res = min(res, m.second);
        }
    }

    cout << (res == INT_MAX ? -1 : res) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}