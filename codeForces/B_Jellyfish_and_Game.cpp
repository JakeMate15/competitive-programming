#include<bits/stdc++.h>
using namespace std;

#define forn(i,n)       for(int i=0; i<n; i++)
#define forr(i,a,n)     for(int i=a; i<n; i++)
#define fore(i,a,n)     for(int i=a; i<=n; i++)
#define fornd(i,n)      for(int i=n; i>=0; i--)
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define pb              push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

void sol(){
    int n, m, k;
    cin >> n >> m >> k;

    multiset<int> a, b;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }

    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }

    auto minA = a.begin();
    auto maxB = prev(b.end());
    int mnA = *minA, mxB = *maxB;

    if(k & 1) {

        if(mnA < mxB) {
            a.erase(minA);
            a.insert(mxB);

            b.erase(maxB);
            b.insert(mnA);
        }
    }
    else{

        if(mnA < mxB) {
            a.erase(minA);
            a.insert(mxB);

            b.erase(maxB);
            b.insert(mnA);
        }

        auto maxA = prev(a.end());
        auto minB = b.begin();
        int mxA = *maxA, mnB = *minB;

        if(mxA > mnB) {
            a.erase(maxA);
            a.insert(mnB);

            b.erase(minB);
            b.insert(mxA);
        }
        
    }

    ll res = 0;
    for(auto x: a) {
        res += x;
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