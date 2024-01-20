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
    int n, q;
    cin >> n >> q;

    map<int, set<int>> st;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        st[x].insert(i);
    }

    while(q--) {
        cerr << "==============\n";
        int x;
        cin >> x;

        for(auto [num, ss]: st) {
            cerr << num << ": ";
            for(auto x: ss) {
                cerr << x << " ";
            }
            cerr << "\n";
        }

        auto it = st.lower_bound(x);
        
        if(it == st.end()) {
            cerr << "final" << "\n";
        }
        else {
            cerr << it->first << "\n";
        }


        if(it == st.end()) {
            cout << 0 << " ";
        }
        else {
            cout << *st[it->first].begin() << " ";
            st[it->first].erase(st[it->first].begin());
            if(st[it->first].empty()) {
                st.erase(it);
            }
        }
    }
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