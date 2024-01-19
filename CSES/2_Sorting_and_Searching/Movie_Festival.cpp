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

    multiset<pair<int, int>> st;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        st.insert({b, a});
    }

    int res = 1;
    pair<int, int> ant = *st.begin();
    for(auto it = next(st.begin()); it != st.end(); it++) {
        if(it->second >= ant.first) {
            res++;
            ant = *it;
        }
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