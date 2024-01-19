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

    vector<int> a(n);
    for(auto &x: a) {
        cin >> x;
    }

    sort(all(a));
    a.erase(unique(all(a)), a.end());

    if(n == 1 || sz(a) == 1) {
        cout << 0 << "\n";
        return;
    }
    
    int res = INT_MAX;
    for(int i = 1; i <= 100; i++) {
        map<int, int> pos;
        for(int j = 0; j < sz(a); j++) {
            for(int k = -1; k <= 1; k++) {
                pos[a[j] + k * i]++;
            }
        }
        for(auto [v, r]: pos) {
            if(r == sz(a)) {
                res = min(res, i);
            }
        }
    }
    cout << (res == INT_MAX ? -1 : res) << "\n";
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