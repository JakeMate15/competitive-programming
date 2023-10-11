#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl              cout << "\n";
typedef long long ll;
typedef long double ld;

const int mx = 2e5 + 5;

void sol(){
    int n;
    cin >> n;

    unordered_map<int, int> m;
    int res = -1;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m[x]++;
        if(m[x] >= 3) {
            res = x;
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