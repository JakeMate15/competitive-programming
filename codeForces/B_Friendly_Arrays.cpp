#include<bits/stdc++.h>
using namespace std;
 
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl              cout << "\n";
typedef long long ll;

void sol(){
    int n, m, x;
    cin >> n >> m;

    vector<int> a(32, 0);
    for(int i = 0; i < n; i++) {
        cin >> x;
        for(int j = 0; j < 32; j++) {
            if(x & (1 << j)) {
                a[j]++;
            }
        }
    }

    int msk = 0;
    for(int i = 0; i < m; i++) {
        cin >> x;
        msk |= x;
    }

    int mn = 0, mx = 0;
    for(int i = 0; i < 32; i++) {
        if(a[i] & 1) {
            mx |= 1 << i;

            mn |= 1 << i;
            if(!(n & 1) && (msk & (1 << i))) {
                mn &= ~(1 << i);
            }
        }
        else{
            if((n & 1) && (msk & (1 << i))) {
                mx |= 1 << i;
            }
        }
    }

    deb(mn); debln(mx);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    cin>>t;
    while(t--){
        sol();
    }

    return 0;
}
