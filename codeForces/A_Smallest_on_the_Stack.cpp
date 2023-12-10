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
    int q;
    cin >> q;

    vector<pair<int, int>> a;
    a.emplace_back(-1, INT_MAX);

    while (q--) {
        string op;
        cin >> op;
        int n;

        if (op == "PUSH") {
            cin >> n;
            a.emplace_back(n, min(n, a.back().second));
        } 
        else if (op == "POP") {
            if (a.size() > 1) {
                a.pop_back();
            }
            else {
                cout << "EMPTY\n";
            }
        } else if (op == "MIN") {
            if (a.size() > 1) {
                cout << a.back().second << "\n";
            } 
            else {
                cout << "EMPTY\n";
            }
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