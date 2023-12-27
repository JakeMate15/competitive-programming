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

    bool f = 1;
    int ultimo = a[0];
    cout << 1;
    for(int i = 1; i < n; i++) {
        if(f && ultimo <= a[i]) {
            cout << 1;
            ultimo = a[i];
        }
        else if(f && a[i] <= a[0]) {
            f = 0;
            cout << 1;
            ultimo = a[i];
        }
        else if(!f && ultimo <= a[i] && a[i] <= a[0]) {
            cout << 1;
            ultimo = a[i];
        }
        else {
            cout << 0;
        }
    }
    cout << "\n";
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