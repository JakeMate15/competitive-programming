#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(int i=(a); i<n; i++)
#define fore(i,a,n) for(int i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

typedef pair<int,int> pii;

bool comp(pii a, pii b){ 
        return (a.first-a.second) > (b.first-b.second); 
}

int n;
vector<pii> v;
vi a;
set<int> s;

int bs(int l,int r,int t){
        while(l <= r){
                int mid=(l+r)/2;
                auto it = s.begin();
                advance(it,mid);
                if(*it==t)
                        return mid;
                else if(*it > t)
                        r=mid-1;
                else
                        l=mid+1;
        }
        
        return -1;
}



void sol(){
        cin >> n;
        v.resize(n);
        forn(i,n) 
                cin >> v[i].first;
        forn(i,n) 
                cin >> v[i].second;

        sort( all(v), comp );

        for(int i=n-1; i>=0; i--) 
                a.push_back( v[i].first - v[i].second );

        lli res = 0;
        int aux,found;
        //a.pb( v[n-1].fi - v[n-1].se );
        forn(i,n-1){
                aux = -( v[i].first - v[i].second );
                auto it = upper_bound(a.begin(),a.begin()+(n-(i+1)),aux);
                found = it-a.begin();
                //cout << "i: " << i << endl;
                //cout << "found: " << found << endl;
                //cout << "found items: " << (n-(i+1)) - found << endl;
                //a.pb( v[i].fi - v[i].se);
                res += (n-(i+1) - found);
        }

        debug(res);

}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();

}