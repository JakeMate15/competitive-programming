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
    int n, t;
    cin >> n >> t;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] += i;
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int res = -2, mx = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] <= t && b[i] > mx) {
            res = i;
            mx = b[i];
        }
    }

    cout << ++res << "\n";
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