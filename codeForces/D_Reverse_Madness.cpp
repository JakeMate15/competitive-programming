#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl()            cout << "\n"
typedef long long ll;

void sol(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    
    vector<int> a(k), b(k);
    for(auto &x: a) {
        cin >> x;
    }
    for(auto &x: b) {
        cin >> x;
    }

    int q;
    cin >> q;
    vector<int> f(n + 1, 0);

    while(q--) {
        int x; 
        cin >> x;
        int i = upper_bound(all(a), x) - a.begin() - 1;
        int l = min(x, a[i] + b[i] - x) - 1, r = max(x, a[i] + b[i] - x);

        f[l]++;
        f[r]--;
    }   

    for(int i = 1; i <= n; i++) {
        f[i] += f[i - 1];
    }


    for(int i = 0; i < k; i++) {
        int l = a[i] - 1, r = b[i] - 1;

        while(l < r) {
            if((f[l] & 1) && (f[r] & 1)) {
                swap(s[l], s[r]);
            }
            l++;
            r--;
        } 
    }

    debln(s);
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




//jihgedcdga
//jihgedcdga

/*

00110110
01010110

*/