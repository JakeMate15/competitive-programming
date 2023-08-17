#include<bits/stdc++.h>
using namespace std;

#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(int i=(a); i<n; i++)
#define fore(i,a,n) for(int i=(a); i<=n; i++)
#define all(v)	    v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"
#define sz(a)       (int)a.size()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int mod = 1e9+7;

void sol(){
    int n;
    cin>>n;

    int pref[n+1];
    pref[0] = 0;
    fore(i,1,n){
        cin>>pref[i];
        pref[i]+=pref[i-1];
    }

    /*
    fore(i,1,n) cout << pref[i] << " ";
    cout << endl;
    */

    int l=1,r=n,m,aux;
    while(l<=r){
        m = (l+r)/2;
        //cout << "m es: " << m << "\n";

        cout << "? " << (m) << " ";
        fore(i,1,m)   cout << i << " "; 
        cout << "\n";

        cin>>aux;

        if(aux>pref[m]) r = m-1;
        else            l = m+1;

    }

    cout << "! " << r+1 << "\n";
}

int main(){IO
	int t=1;
	cin>>t;
	while(t--)  sol();
}