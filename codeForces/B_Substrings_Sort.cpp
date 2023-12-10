#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

bool cmp (string a, string b) {
    return sz(a) < sz(b);
}

void sol(){
    int n;
    cin >> n;

    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a), cmp);
    
    string ant = a[n - 1];
    for(int i = n - 1; i >= 0; i--) {
        
        if(ant.find(a[i]) == string::npos) {
            cout << "NO\n";
            return;
        }

        ant = a[i];
    }

    cout << "YES\n";
    for(auto x: a) {
        cout << x << "\n";
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