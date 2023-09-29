#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl()            cout << "\n"
typedef long long ll;

void sol(){
    int n;
    cin >> n;

    vector<ll> sets(n);
    ll u = 0;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;

        for(int j = 0; j < k; j++) {
            int x;
            cin >> x;
            x--;
            sets[i] |= (1LL << x);
        }
        u |= sets[i];
    }

    int res = 0;
    for(int i = 0; i < 55; i++) {
        ll curr = 0;
        if(u & (1LL << i)) {
            for(int j = 0; j < n; j++) {
                if(!(sets[j] & (1LL << i))) {
                    curr |= sets[j];
                }
            }
            res = max(res, __builtin_popcountll(curr));
        }
    }

    debln(res);;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    cin>>t;
    while(t--){
        sol();
    }

    return 0;
}