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
    int n, k;
    cin >> n >> k;

    ll prod = 1;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        prod *= x;
    }

    if(prod > 2023 || 2023 % prod ) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        cout << 2023 / prod << " ";
        for(int i = 0; i < k - 1; i++) {
            cout << 1 << " ";
        }
        nl;
    }
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