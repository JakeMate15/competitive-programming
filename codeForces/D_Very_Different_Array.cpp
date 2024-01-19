#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol(){;
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    multiset<int> b;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));

    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }

    int i = 0, j = n - 1;
    ll res = 0;
    for(int k = 0; k < n; k++) {
        ll i1 = abs(a[i] - *b.begin()), i2 = abs(a[i] - *b.rbegin());
        ll j1 = abs(a[j] - *b.begin()), j2 = abs(a[j] - *b.rbegin());

        res += max(max(i2, i2), max(j1, j2));

        if(max(i1, j1) > max(i2, j2)) {
            b.erase(b.lower_bound(*b.begin()));
            if(i1 > j1) 
                i++;
            else 
                j--;
        }
        else {
            b.erase(b.lower_bound(*b.rbegin()));
            if(i2 > j2) 
                i++;
            else 
                j--;
        }
    }

    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}