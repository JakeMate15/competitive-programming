#include<bits/stdc++.h>
using namespace std;

#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(int i=(a); i<n; i++)
#define fore(i,a,n) for(int i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"
#define sz(a)       (int)a.size()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

void sol(){
    int n,x;cin>>n>>x;

    vi a(n);
    vector<bool> completo(n);
    for(int &x: a)  cin>>x;
    sort(all(a));

    int i=0,j=n-1,res=0;
    ll aux;
    while(i<j){
        aux = a[i] + a[j];
        if( aux > x ){
            j--;
        }
        else{
            res++;
            completo[i] = completo[j] = true;
            i++;
            j--;
        }
    }

    for(bool x: completo)   res+= x==false;

    debug(res);
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}