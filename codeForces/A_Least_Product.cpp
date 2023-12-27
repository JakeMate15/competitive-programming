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
    int sgn = 1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] < 0) {
            sgn *= -1;
        }
        else if(a[i] == 0) {
            sgn *= 0;
        }
    }

    if(sgn <= 0) {
        cout << "0\n" << "\n";
    }
    else {
        cout << 1 << "\n";
        cout << 1 << " 0" << "\n";
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