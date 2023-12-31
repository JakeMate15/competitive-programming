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

bool subarrayWithSum(vector<int> a, ll sum) {
    set<ll> aux = {0};
    ll currSum = 0;

    for(int i = 0; i < sz(a); i++) {
        currSum += a[i];

        if(aux.count(currSum)) {
            return true;
        }
        
        aux.insert(currSum);
    }

    return false;
}

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

    if(subarrayWithSum(a, 0)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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