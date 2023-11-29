#include<bits/stdc++.h>
using namespace std;
 
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
 
typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n, 0), par(n, 0);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        par[i] = x % 2 == 0 ? 0 : 1;
        while(x % k != 0) {
            x++;
            a[i]++;
        }
        
    }

    sort(all(a));
    sort(all(par));
    
    if(k == 4) {
        cout << min(par[0] + par[1], a[0]) << "\n";
    }
    else { 
        cout << a[0] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    cin>>t;

    while(t--){
        sol();
    }

    return 0;
}