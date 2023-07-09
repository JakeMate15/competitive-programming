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
    int n;cin>>n;

    if(n&1){
        if( ((n-1)/2)&1 ){
            debug("YES");
            debug(n/2+1);
            for(int i=1; i<=n/2; i+=2){
                cout << i << " " << n-i << " ";
            }
            debug("");

            debug(n/2);
            cout << n << " ";
            for(int i=2; i<n/2; i+=2){
                cout << i << " " << n-i << " ";
            }
            debug("");

        }  
        else{
            debug("NO");

        }
    }
    else{
        if( (n/2)&1 )   debug("NO");
        else{
            debug("YES");
            debug(n/2);
            for(int i=1; i<(n/2); i+=2){
                cout << i << " " << n+1-i << " ";
            }
            debug("");

            debug(n/2);
            for(int i=2; i<=(n/2); i+=2){
                cout << i << " " << n+1-i << " ";
            }
            debug("");

        }
    }
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}