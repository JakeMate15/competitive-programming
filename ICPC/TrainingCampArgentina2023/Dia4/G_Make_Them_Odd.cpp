#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)
#define all(v)          v.begin(),v.end()
#define borra(s)        s.erase(unique(all(s)),s.end())
#define YES                 cout << "YES\n"
#define NO                  cout << "NO\n"
#define debug(a)        cout << a << "\n"

void sol(){
        int n, x, res=0;
        cin>>n;
        set <int, greater <int> > pares;
        set <int>::iterator it, it2;
        while(n--){
                cin>>x;
                if(x%2 ==0)
                        pares.insert(x);
        }

        it=pares.begin();
        while(it!=pares.end()){
                it2=it;
                x=*it/2;
                if(x%2==0)
                        pares.insert(x);
                it++;
                res++;
                pares.erase(it2);
        }

        debug(res);        
}

int main(){IO
        int t=1;
        cin>>t;
        while(t--)  sol();
}
