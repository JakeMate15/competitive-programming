#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 1e6 + 5;

int criba[MX];

void sol(){
    int x;
    cin >> x;
    cout << criba[x] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    for(int i = 1; i <= MX; i++) {
        for(int j = i; j <= MX; j += i) {
            criba[j]++;
        }
    }

    while(t--){
        sol();
    }

    return 0;
}