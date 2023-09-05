#include<bits/stdc++.h>
using namespace std;

#define IO    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)	for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(int i=(a); i<n; i++)
#define fore(i,a,n) for(int i=(a); i<=n; i++)
#define all(v)		v.begin(),v.end()
#define borra(s)	s.erase(unique(all(s)),s.end())
#define YES			cout << "YES\n"
#define NO			cout << "NO\n"
#define debug(a)	cout << a << "\n"
#define sz(a)		(int)a.size()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
    
const int mod = 1e9+7;

void sol(){
    int T = 1,n,k;
    cin>>n>>k; 
 
    string s;
    cin>>s;
    vector<pair<char,int>> v;
 
    for(int i = 0;i<n;){
        int j = i;
        while(j<n && s[i]== s[j]){
            j++;
        }
        v.push_back({s[i],j-i});
        i = j;
    }
 
    if(sz(v)==1){
        debug(-1);
        return;
    }
 
    if(v[0].first == v.back().first){
        v[0].second+=v.back().second;
        v.pop_back();
    }
    
    int N = sz(v);
    for(int i = 0;i<N;i++)
        v.push_back(v[i]);
 
    int ans = 0;
    map<char,int> mp;
 
    int l = 0,r = 0;
    int bl = -1,br = -1;
    int chars = 0;
    while(l<sz(v)){
        if(r<l)r = l;
        
        while(r<sz(v)){
            if(r-l==N)							break;
            if(mp[v[r].first]+v[r].second>k)	break;
            mp[v[r].first]+=v[r].second;
            chars+=v[r].second;
            r++;
        }
        if(chars>ans){
            bl = l;
            br = r;
            ans = chars;
        }
        if(l<r){
            mp[v[l].first]-=v[l].second;
            chars-=v[l].second;
        }
        l++;
    }
    if(ans==0){
        debug(-1);
        return;
    }
 
    debug(ans);
    forr(i,bl,br){
        forn(j,v[i].second){
            cout << v[i].first;
        }
    }
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)    sol();
}