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

vector<lli> total,pa,rk;

int parent(int a){
    if(pa[a] == a)
        return a;
    return pa[a] = parent(pa[a]);
}

void join(int a, int b){
    a = parent(a);
    b = parent(b);
    if(a != b)
    {
        if(rk[b] > rk[a])
            swap(a,b);
        pa[b] = a;
        if(rk[b] == rk[a])rk[a]++;
        total[a] = min(total[a], total[b]);
    }
}

void sol(){
        int n,m;
        cin>>n>>m;

        total.resize(n+1);
        pa.resize(n+1);
        rk.resize(n+1);

        fore(i,1,n){
                cin>>total[i];
                pa[i] = i;
        }

        forn(i,m){
                int a,b;
                cin>>a>>b;
                join(a,b);
        }

        lli res = 0;
        fore(i,1,n){
                if(parent(i)==i)
                        res+=total[i];
        }

        debug(res);
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}
