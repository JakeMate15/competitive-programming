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
        lli n,t;
        cin>>n>>t;
        int i,j,aux,sum=0;

        vector<lli> a(n+1);
        a[0] = 1;
        fore(i,1,n){
                cin>>aux;
                a[i] = a[i-1] + aux;
        }

        i = 1,j=0;
        
        while(i<=n){
                if(a[i]-a[j]>t)
                        j++;
                else{
                        sum=max(sum,i-j);
                        i++;
                }
        }

        debug(sum);
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}
