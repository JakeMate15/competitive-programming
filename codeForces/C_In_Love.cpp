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

    multiset<int> l, r;
    while(n--) {
        char op;
        int a, b;
        cin >> op >> a >> b;

       
        if(op == '+') {
            l.insert(a);
            r.insert(b);
        }
        else {
            l.erase(l.find(a));
            r.erase(r.find(b));
        }

        if(sz(l)) {
            int mn = *r.begin(), mx = *l.rbegin();
            cout << (mx > mn ? "YES" : "NO") << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
        
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    // cin>>t;

    while(t--){
        sol();
    }

    return 0;
}