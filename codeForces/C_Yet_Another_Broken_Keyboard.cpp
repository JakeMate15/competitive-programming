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
    int n, m;
    string s;
    cin >> n >> m >> s;

    set<char> st;
    for(int i = 0; i < m; i++) {
        char x;
        cin >> x;
        st.insert(x);
    }

    ll res = 0;
    for(int i = 0; i < sz(s); i++) {
        ll curr = 0;
        while(st.count(s[i]) && i < sz(s)) {
            curr++;
            i++;
        }

        res += (curr * (curr + 1)) / 2;
    }
    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}