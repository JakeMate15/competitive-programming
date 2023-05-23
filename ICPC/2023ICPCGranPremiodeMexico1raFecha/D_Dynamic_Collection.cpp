//https://codeforces.com/gym/104375/problem/D
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(ll (i)=0; i<n; i++)
#define forr(i,a,n) for(ll i=(a); i<n; i++)
#define fore(i,a,n) for(ll i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define debug(a)    cout << a << "\n"

int main(){IO
    int n,q;cin>>n>>q;
    vector<int> a(n);
    forn(i,n)   cin>>a[i];
    sort(all(a));

    while(q--){
        int t;cin>>t;
        if(t==1){
            int x;cin>>x;
            int pos = upper_bound(all(a),x)-a.begin();
            if(pos<a.size() && a[pos-1]==x)     continue;
            else if(x>a.back())                 a.push_back(x);
            else{
                if(pos<a.size())   a[pos] = x;
            }
        }
        else{
            int l,r;cin>>l>>r;
            int inf,sup;
            inf = lower_bound(all(a),l)-a.begin();
            sup = upper_bound(all(a),r)-a.begin();
            debug(sup-inf);
        }
    }
    return 0;
}