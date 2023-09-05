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
        int xa,xb,xf,ya,yb,yf;

        cin>>xa>>ya>>xb>>yb>>xf>>yf;

        int dist = abs(xa - xb) + abs(ya - yb);

        if ((xa == xb && xb == xf && (min(ya,yb) < yf && yf < max(ya,yb))) ||
                (ya == yb && yb == yf && (min(xa,xb) < xf && xf < max(xa,xb))))
                dist += 2;
        debug(dist);
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}