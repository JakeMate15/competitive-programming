#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
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

void sol(){
        int n;
        cin>>n;
        vector<ll> v(n);
        vector<ll> t(n);

        for(auto &x: v) cin>>x;
        for(auto &x: t) cin>>x;

        vector<ll> total(n);
        vector<ll> prefix(n);
        vector<ll> ans(n);
        forn(i,n){
                if(i > 0) prefix[i] += prefix[i-1];
                prefix[i] += t[i];
        }

        forn(i,n){
                ll temp;
                if(v[i]==0)     continue;

                if(i>0) temp = v[i] + prefix[i-1];
                else    temp = v[i];

                int pos = lower_bound(all(prefix), temp) - prefix.begin();
                if(pos>=n){
                        total[i]++;
                }
                else if(prefix[pos] == temp){
                        total[i]++;
                        if(pos + 1 < n) total[pos+1]--;
                }
                else{
                        total[i]++;
                        total[pos]--;
                        if(pos>0)       ans[pos] += temp - prefix[pos-1];
                        else            ans[pos] += temp;
                }
                //debug("");
        }
        
        ll temp = 0;
        forn(i,n){
                //cout << total[i] << " ";
                temp += total[i];
                ans[i] += temp * t[i];
                cout << ans[i] << ' ';
        }
        

}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}