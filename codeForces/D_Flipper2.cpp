#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"
#define eb(a)       emplace_back(a)

void sol(){

    /*
    int n;cin>>n;
    vector<int> ans;
    int a[n];
    forn(i,n)   cin>>a[i];

    int posMax;
    if(a[0] == n)   posMax = max_element(a+1,a+n)-a;
    else            posMax = max_element(a,a+n)-a;

    forr(i,posMax,n)    cout << a[i] << " ";
    int r = posMax-1;
    cout << a[r];

    debug("");
    */
    int n; cin >> n;
    vector<int> p(n);
    for (auto &e : p) cin >> e;

    int r = 0;
    for (int i = 0; i < n; ++i) {
        if (p[min(n-1, r+1)] <= p[min(n-1, i+1)]) {
            r = i;
        }
    }
    vector<int> ans;
    for (int i = r + 1; i < n; ++i) ans.eb(p[i]);
    
    
    //ans.eb(p[r]);
    /*
    for (int i = r-1; i >= 0; --i) {
        if (p[i] > p[0]) {
            ans.eb(p[i]);
        } else {
            for (int j = 0; j <= i; ++j) {
                ans.eb(p[j]);
            }
            break;
        }
    }*/
    for (auto e : ans) cout << e << ' ';
    cout << endl;
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}