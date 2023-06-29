#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(ll (i)=0; i<n; i++)
#define forr(i,a,n) for(ll i=(a); i<n; i++)
#define fore(i,a,n) for(ll i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"
#define sz(a)       (int)a.size()

void sol(){
    int n,m;
    cin>>n>>m;

    vector<pii> seg(m);
    for(auto &x: seg){
        int a,b;cin>>a>>b;
        x={a,b};
    }

    int q;cin>>q;
    vi querys(q);
    for(int &x: querys)
        cin >> x;

    int l=-1,r=q,mid;

    while(r>l+1){
        mid = l+(r-l)/2;
        debug(m);

        vi a(n+1,0);
        fore(i,0,mid)
            a[querys[i]] = 1;

        vi pref(n+1,0);
        fore(i,1,n)
            pref[i] = pref[i-1] + a[i];

        bool ok = false;
        for(auto x: seg){
            if( (x.first-x.second+1)/2 < (pref[x.second] - pref[x.first-1]) ){
                ok=true;
                break;
            }
        }

        if(ok)  r = m;
        else    l = m;
    }

    debug(m);
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  
        sol();

    return 0;
}