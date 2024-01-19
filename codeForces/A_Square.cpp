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
    vector<int> x(4), y(4);
    for(int i = 0; i < 4; i++) {
        cin >> x[i] >> y[i];
    }

    sort(all(x));
    sort(all(y));

    cout << ((x[3] - x[0]) * (y[3] - y[0])) << "\n";
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