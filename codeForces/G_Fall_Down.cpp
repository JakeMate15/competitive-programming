#include<bits/stdc++.h>
using namespace std;

#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(int i=(a); i<n; i++)
#define fore(i,a,n) for(int i=(a); i<=n; i++)
#define all(v)		v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"
#define sz(a)       (int)a.size()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

void sol(){
    int n,m;
    cin>>n>>m;
    char a[n][m];
    
    forn(i,n){
        forn(j,m){
            cin>>a[i][j];
        }
    }

    
    forn(i,m){
        for(int j=n-1; j>0; j--){
            //cout << j << " " << i << endl;
            //cout << a[j][i] << " " << a[j-1][i] << endl;
            if(a[j][i] == 'o' || a[j-1][i] == 'o') continue;
            char aux = a[j][i];
            a[j][i] = a[j-1][i];
            a[j-1][i] = aux;
        }
        //debug("");
    }
    
    forn(i,n){
        forn(j,m){
            cout << a[i][j];
        }
        debug("");
    }
    
    
    debug("");
}

int main(){
	int t=1;
	cin>>t;
	while(t--)  
		sol();
}