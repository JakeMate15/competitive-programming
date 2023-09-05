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

template <typename A, typename B>
multimap<B,A> flip_map(unordered_map<A,B> &src){
    multimap<B,A> dst;

    for(auto it = src.begin(); it!=src.end(); it++)
        dst.insert(pair<B,A> (it->second, it->first));

    return dst;
}

void sol(){
    int c,r,k;cin>>c>>r>>k;
    unordered_map<int,int> a;
    
    int lec;
    forn(i,r){
        cin>>lec;
        if(a.count(lec))    a[lec]++;
        else                a[lec]=1;
    }

    multimap<int,int> reverso = flip_map(a);

    int res = 0;
    for(auto it=reverso.rbegin(); it!=reverso.rend(); it++){
        if(k<=0)    break;
        else        res+=it->first;
        k--;
    }
    debug(res);
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}