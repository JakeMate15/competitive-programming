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

ll sum(int numero){
    if(!numero) return 0;
 
    ll res = 0;
 
    while (numero != 0) {
        res += numero % 10;
        numero /= 10;       
    }
 
    return res;
}

void sol(){
    int n,k;
    cin>>n>>k;

    vector<int> a(1e6+5,0);
    int mx = 0;
    forn(i,n){
        int x;
        cin>>x;
        a[x]++;
        mx = max(mx,x);
    }

    while(k>=0 && mx>=0){
        int nvo,rep;
        rep = a[mx];

        if(k-rep <= 0) break;

        k-=rep;
        nvo = mx-sum(mx);
        a[nvo]+=rep;
        a[mx] = 0;
        while(a[mx]<=0 && mx>=0) mx--;
    }

    mx = max(mx,0);

    debln(sum(mx));

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