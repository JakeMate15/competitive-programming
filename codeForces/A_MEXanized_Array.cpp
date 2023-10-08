#include<bits/stdc++.h>
using namespace std;
 
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl              cout << "\n";
typedef long long ll;

void sol(){
    int n, k, x;
    cin >> n >> k >> x;

    if(k > n || k - 1 > x) {
        debln(-1);
        return;
    }

    int res = 0;
    for(int i = 0; i < k; i++) {
        res += i;
    }

    for(int i = k; i < n; i++) {
        res += (x > k ? x : k - 1);
    }
    
    debln(res);
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