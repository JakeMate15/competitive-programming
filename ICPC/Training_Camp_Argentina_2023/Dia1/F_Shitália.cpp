#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef long double ld;
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
        ld n,R,r;
        cin>>n>>R>>r;

        double pi = acos(-1.0);
        ld aux = R * r * sin( (360.0 / (2.0 * n)) * 2.0 * pi / 360.0);

        cout << fixed << setprecision(14) << aux * n << endl;
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}