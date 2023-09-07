#include<bits/stdc++.h>
using namespace std;

#define forn(i,n)       for(int i=0; i<n; i++)
#define forr(i,a,n)     for(int i=a; i<n; i++)
#define fore(i,a,n)     for(int i=a; i<=n; i++)
#define fornd(i,n)      for(int i=n; i>=0; i--)
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define pb              push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

ll gcd(ll a, ll b) {return a == 0? b: gcd(b%a,a);}
ll lcm(ll a, ll b) {return a * (b / gcd(a,b));}

void sol(){
    ll n,x,y;
    cin>>n>>x>>y;

    ll mcd = lcm(x,y);
    ll juntos = n/mcd;
    x = n/x;
    y = n/y;
    x-=juntos;
    y-=juntos;

    ll res = 0;
    res-=((y*(y+1))/2);
    res+=((n-(n-x+1)+1)/2*((n-x+1)+n));
    debln(res);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    cin>>t;
    while(t--){
        sol();
    }

    return 0;
}