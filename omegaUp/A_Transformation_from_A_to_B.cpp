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
    int a,b;
    cin>>a>>b;
    vi res = {b};

    while(b!=a && b>a){
        if(b&1){
            b--;
            if(b%10){
                debln("NO");
                return;
            }
            b/=10;
        }
        else{
            b/=2;
        }
        res.pb(b);
    }

    reverse(all(res));
    if(res[0]!=a){
        debln("NO");
        return;
    }
    else{
        debln("YES");
        debln(sz(res));
        for(auto x: res){
            deb(x);
        }
        debln("");
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    //cin>>t;
    while(t--){
        sol();
    }

    return 0;
}