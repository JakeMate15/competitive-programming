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

    vector<int> a(n);
    int impares = 0;
    for(auto &x: a) {
        cin >> x;
        impares += (x & 1);
    }

    if(impares < k || ((impares - k) & 1)) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    for(int i = 0; i < n; i++) {
        if(k == 1) {
            break;
        }
        if(a[i] & 1) {
            cout << i + 1 << " ";
            k--;
        }
    }

    cout << n << "\n";
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