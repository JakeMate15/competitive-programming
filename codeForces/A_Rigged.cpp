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

//Revisar en que casos cuantos casos es viable tomar el otro

void sol(){
    int n;
    cin >> n;

    int gP, gR;
    cin >> gP >> gR;

    int iguales = 0, mejores = 0;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        if(u >= gP && v >= gR) {
            iguales++;
        }
    }

    if(iguales) {
        debln(-1);
    }
    else{
        debln(gP);
    }
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