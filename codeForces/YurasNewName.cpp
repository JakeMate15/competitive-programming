#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)

void sol(){
    string s;cin>>s;
    if(s.size()==1){
        s[0]=='^'?(cout<<1<<"\n"):(cout<<2<<"\n");
        return;
    }

    int ans = 0;
    if(s[0]=='_')   ans++;
    if(s.back()=='_')   ans++;
    forn(i,s.size()-1){
        if(s[i]=='_' && s[i+1]=='_')    ans++;
    }
    cout << ans << endl;
}

int main(){IO
    int t;cin>>t;
    while(t--)  sol();
}