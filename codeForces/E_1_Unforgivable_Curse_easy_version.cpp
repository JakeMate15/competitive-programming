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

void sol(){
    int n,k;
    string s1,s2;
    cin>>n>>k>>s1>>s2;

    forn(i,n){
        if(i-k<0 && i+k>=n){
            if(s1[i]!=s2[i]){
                debug("NO");
                return;
            }
        }
    }

    sort(all(s1));
    sort(all(s2));

    if(s1==s2)  debug("YES");
    else        debug("NO");
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}