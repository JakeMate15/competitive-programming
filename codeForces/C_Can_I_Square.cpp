#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

bool pot2(ll n) {
    return __builtin_popcountll(n) == 1;
}

void sol(){
    int n;
    cin >> n;

    vector<int> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    ll sq = sqrt(sum);
    cout << (sq * sq == sum ? "YES" : "NO") << "\n";
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