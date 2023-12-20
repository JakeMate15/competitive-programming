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
    string s;
    cin >> n >> s;

    vector<int> a(26);
    for(auto x: s) {
        a[x - 'a']++;
    }

    auto mx = *max_element(all(a));
    if(mx > n / 2) {
        cout << 2 * mx - n << "\n";
    }
    else {
        cout << (n & 1)<< "\n";
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