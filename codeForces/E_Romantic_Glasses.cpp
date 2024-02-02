#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

/*

Problemas comunes
maxSubArraySum
subarrayWithSum
sumAllSubArrays
numberOfSubaarraysWithOddSum

*/

void sol(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(!(i & 1)) {
            a[i] = -a[i];
        }
    }

    ll pref = 0, sum = 0, cnt = 0;
    map<ll, int> mp;
    for (int i = 0; i < n; i++) {
        pref += a[i];
        if (pref == sum)    cnt++;
        cnt += mp[pref - sum];
        mp[pref]++;
    }

    cout << (cnt ? "YES" : "NO") << "\n";
    
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