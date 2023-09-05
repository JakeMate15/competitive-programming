#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
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

const int mx = 2*1e5+5;

struct nodo{
        ll pos;
        ll dinero;
}jg[mx];
ll ori[mx];

bool cmp(nodo a, nodo b){
        if(a.dinero < b.dinero) return true;
        return false;
}

void sol(){
        int n;
        cin>>n;

        fore(i,1,n){
                cin>>jg[i].dinero;
                ori[i] = jg[i].dinero;
                jg[i].pos = i;
        }

        ll cont = n;
        ll vmax = 0;
        sort(jg+1,jg+n+1,cmp);
        ll acum = 0;
        forr(i,1,n){
                if(jg[i].dinero<jg[i+1].dinero && acum!=jg[i+1].dinero){
                        vmax = jg[i+1].dinero;
                        cont = n - i;
                }
                acum = jg[i+1].dinero;
                jg[i+1].dinero+=jg[i].dinero;
        }
        debug(cont);
        fore(i,1,n){
                if(ori[i]>=vmax){
                        cout << i << " ";
                }
        }
        debug("");
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}