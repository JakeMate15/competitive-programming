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
        int x,y;
        bool usado[4],aux[2];

        int p,r,i;
        cin>>x>>y;
        memset(usado,false,sizeof(usado));
        memset(aux,false,sizeof(aux));

        if(x>=0 && y>=0)
                usado[0] = true;
        if(x<=0 && y>=0)
                usado[1] = true;
        if(x<=0 && y<=0)
                usado[2] = true;
        if(x>= 0 && y<=0)
                usado[3] = true;

        r = (int)(sqrt((double)(x*x+y*y))+1e-9);
        forn(i,4){
                if(usado[i]){
                        if(r*r == x*x+y*y)
                                aux[(i+r)%2] = aux[(i+r+1)%2] = true;
                        else
                                aux[(i+r)%2] = true;
                }
        }

        if(aux[0])
                debug("black");
        else
                debug("white");
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}