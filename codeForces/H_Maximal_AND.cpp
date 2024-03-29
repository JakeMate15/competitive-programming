#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl              cout << "\n";
typedef long long ll;
typedef long double ld;

void sol(){
    int n, k;
    cin >> n >> k;

    vector<int> bits(32, 0);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        for(int j = 0; j <= 30; j++) {
            if(x & (1 << j)) {
                bits[j]++;
            }
        }
    }

    ll res = 0;
    for(int i = 30; i >= 0; i--) {
        if(n - bits[i] <= k) {
            res |= (1 << i);
            k -= (n - bits[i]);
        }
    }

    debln(res);

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