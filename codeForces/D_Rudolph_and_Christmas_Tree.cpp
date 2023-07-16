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
    long double triangulos, b,h;
    cin>>triangulos>>b>>h;

    vector<long double> a(triangulos);
    for(auto &x: a)  cin>>x;

    if(triangulos == 1){
        debug( (double)(b*h)/2 );
    }
    else{
        long double res = (1.0*b*h)/(1.0*2);
        forn(i,triangulos-1){
            if( a[i]+h <= a[i+1] ){
                res+=(1.0*b*h)/(1.0*2);
            }
            else{
                long double aux = (a[i+1]-a[i])*1.0;
                long double B = (1.0*h-aux)/h*(1.0*b);
                res+= ( 1.0*(b+B)/2 )*aux;
            }
        }
        cout << fixed << setprecision(12) << res << endl;
    }
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}