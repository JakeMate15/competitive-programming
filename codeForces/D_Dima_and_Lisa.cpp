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

bool primo(int n){
    if(n<2) return false;
    for (int x = 2; x*x <= n; x++) {
        if (n%x == 0) return false;
    }
    return true;
}
 
void sol(){
    int n;
    cin>>n;
 
    if(primo(n)){
        debln(1);
        debln(n);
    }
    else if( primo(n-2) ){
        debln(2);
        deb(2);debln(n-2);
    }
    else{
        debln(3);
        for(int i=3; i<=n; i+=2){
            for(int j=3; j<=n; j+=2){
                if(primo(i) && primo(j) && primo(n-i-j)){
                    deb(i);deb(j);debln(n-i-j);
                    return;
                }
            }
        }
    }
    
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