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

void sol(){
    ll n;cin>>n;
    string aux = to_string(n);

    ll res = 0;
    while(n){
        ll mx = (*max_element(all(aux))) - '0';
        res++;
        n-=mx;
        aux = to_string(n);
    }
    debln(res);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    //cin>>t;
    while(t--){
        sol();
    }

    return 0;
}