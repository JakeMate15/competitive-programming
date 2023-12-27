#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol(){
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> cnt;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    if(sz(cnt) > 2) {
        cout << "No\n";
    }
    else if(sz(cnt) == 1) {
        cout << "Yes\n";
    }
    else {
        int n1 = (*cnt.begin()).second, n2 = (*next(cnt.begin())).second;
        if(n1 == n2 || max(n1, n2) - min(n1, n2) == 1) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
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