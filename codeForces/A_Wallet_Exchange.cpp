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
    ll a, b;
    cin >> a >> b;

    if((a + b) & 1) {
        cout << "Alice\n";
    }
    else {
        cout << "Bob\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}