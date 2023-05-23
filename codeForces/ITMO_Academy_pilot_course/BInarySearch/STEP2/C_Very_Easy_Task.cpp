#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define YES cout<<"Yes\n";
#define NO cout<<"No\n";
#define pb push_back
#define all(v) v.begin(), v.end()
#define sortall(f) sort(all(f))
#define forn(i,n) for(ll i=0;i<n;i++)

typedef long long ll;

const int MX = 2*1e8;

bool ok(int x, int y, int copias, int m){
    return (m/x + m/y)>=copias-1;
}

int main(){IO
    int n,x,y,t=0;
    cin>>n>>x>>y;

    if(n==1){
        cout << min(x,y) << "\n";
        return 0;
    }

    int l=0,m,r=1;
    
    while(!ok(x,y,n,r)) r*=2;
    
    while(r>l+1){
        m = l+(r-l)/2;
        if(ok(x,y,n,m)) r = m;
        else    l=m;
    }

    cout << r+min(x,y) << "\n";    

    return 0;
}