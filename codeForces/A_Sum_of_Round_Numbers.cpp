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

    vector<int> a;
    int pot = 1;
    while(n) {
        a.push_back(n % 10 * pot);
        n /= 10;
        pot *= 10;
    }

    cout << sz(a) - count(all(a), 0) << "\n";
    for(auto x: a) {
        if(x) {
            cout << x << " ";
        }
    }
    nl;
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