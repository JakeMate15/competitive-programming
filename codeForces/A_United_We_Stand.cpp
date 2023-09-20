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
    int n;
    cin>>n;

    vi a(n);
    for(auto &x: a){
        cin>>x;
    }

    sort(all(a));

    if(a[0] == a[n-1]){
        debln(-1);
        return;
    }

    int pos = 0;
    while(a[pos] == a[0])   pos++;
    deb(pos);debln(n-pos);

    forn(i,pos){
        deb(a[i]);
    }
    debln("");

    forr(i,pos,n){
        deb(a[i]);
    }
    debln("");
    
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