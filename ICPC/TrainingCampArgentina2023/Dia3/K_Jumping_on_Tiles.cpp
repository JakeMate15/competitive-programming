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
        string s;
        cin >> s;

        vi rep(26);
        for(auto x:s) {
                rep[x-'a']++;
        }

        int n = s.size();
        int l = min(s[0], s[n-1]) - 'a';
        int r = max(s[0], s[n-1]) - 'a';

        int total = 0;
        fore(i,l,r) {
                total += rep[i];
        }
        
        cout << r - l << " " << total << "\n";
        
        if(s[0] <= s[n-1]) {
                fore(i,l,r){
                        for(int j=0; j<n; j++) {
                                if(s[j] - 'a' == i) 
                                        cout << j + 1 << " ";
                        }
                }
        }
        else {
                for(int i=r; i>=l; i--) {
                        forn(j,n){
                                if(s[j] - 'a' == i) cout << j + 1 << ' ';
                        }
                }
        }
        
        debug("");
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}