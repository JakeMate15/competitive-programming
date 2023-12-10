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
    stack<pair<char, int>> minus, may;
    string s;
    cin >> s;

    for(int i = 0; i < sz(s); i++) {
        if(s[i] == 'B') {
            if(!may.empty()) {
                may.pop();
            }
        }
        else if(s[i] == 'b') {
            if(!minus.empty())
                minus.pop();
        }
        else if(s[i] >= 'a' && s[i] <= 'z') {
            minus.push({s[i], i});
        }
        else {
            may.push({s[i], i});
        }
    }

    vector<pair<char, int>> res;
    while(!minus.empty()) {
        res.push_back(minus.top());
        minus.pop();
    }

    while(!may.empty()) {
        res.push_back(may.top());
        may.pop();
    }

    sort(all(res), cmp);
    for(auto x: res) {
        cout << x.first;
    }
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