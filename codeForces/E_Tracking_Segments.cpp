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

    int l=0,r=q-1,mid;

    while( l<=r){
        mid = (r+l)/2;

        vi a(n+1,0);
        fore(i,0,mid)
            a[querys[i]] = 1;

        vi pref(n+1,0);
        fore(i,1,n)
            pref[i] = pref[i-1] + a[i];

        bool ok = false;
        for(auto x: seg){
            //cout << x.first << "," << x.second << " " << (x.second-x.first+1)/2  << " " << (pref[x.second] - pref[x.first-1]) << "\n";
            if( (x.second-x.first+1)/2 < (pref[x.second] - pref[x.first-1]) ){
                ok=true;
                break;
            }
        }

        if(ok)  r = mid-1;
        else    l = mid+1;

    }

    debug( ((l==q)?-1:l+1) );
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  
        sol();

    return 0;
}