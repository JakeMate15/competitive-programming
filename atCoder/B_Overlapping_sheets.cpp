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

int g[100][100];

void sol(){
    int n;
    cin>>n;

    forn(i,n){
        int a,b,c,d;
        cin>>a>>b>>c>>d;

        forr(j,a,b){
            forr(k,c,d){
                g[j][k] = 1;
            }
        }
    }

    int res = 0;
    forn(i,100){
        forn(j,100){
            if(g[i][j]) res++;
        }
    }

    debln(res);
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