#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

bool isVowel(char ch) {
    return ch == 'a' || ch == 'e';
}

bool isConsonant(char ch) {
    return ch == 'b' || ch == 'c' || ch == 'd';
}


void sol(){
    // cerr << "===========\n";
    int n;
    string s;
    cin >> n >> s;

    // set<char> v = {'a', 'e'}, c = {'b', 'c', 'd'};
    // vector<string> res;
    // int vv = 0, cc = 0, j = 0;
    // for(int i = n - 1; i >= 0; i--) {
    //     string curr = "";
    //     curr += s[i];
    //     cerr << s[i] << "\n";
    //     if(c.count(s[i])) {
    //         curr = s.substr(i - 2, 3);
    //         i -= 2;
    //     }
    //     else {
    //         i -= 1;
    //         curr = s.substr(i - 1, 2);
    //     }
    //     res.push_back(curr);
    //     cerr << curr << "\n";
    //     curr = "";
    // }

    // reverse(all(res));
    // // for(auto x: res) {
    // //     cout << x << " ";

    // // }
    // cerr << "\n";
    // for(int i = 0; i < sz(res) - 1; i++) {
    //     cout << res[i] << ".";
    // }
    // cout << res[sz(res) - 2] << "\n";

    int cc = 0, vv = 0;
    vector<string> res;
    reverse(all(s));
    // cerr << s << "\n";
    string curr = "";
    for(int i = 0; i < n; i++) {
        if(isVowel(s[i])) {
            curr = s.substr(i, 2);
            i += 1;
        }
        else {
            curr = s.substr(i, 3);
            i += 2;
        }
        reverse(all(curr));
        res.push_back(curr);
        // cerr << curr << "\n";
    }
    reverse(all(res));

    for(int i = 0; i < sz(res) - 1; i++) {
        cout << res[i] << ".";
    }
    cout << res[sz(res) - 1] << "\n";
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