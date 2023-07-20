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

    int a[n][m];
    forn(i,n){
        forn(j,m){
            cin>>a[i][j];
        }
    }

    int res = 0;
    forn(i,n){
        forn(j,m){
            int curr = 0;
            int ci = i, cj = j;

            while(ci >= 0 && ci < n && cj >= 0 && cj < m){
                curr+=a[ci][cj];
                ci--;
                cj--;
            }

            ci = i, cj = j;
            while(ci >= 0 && ci < n && cj >= 0 && cj < m){
                curr+=a[ci][cj];
                ci++;
                cj--;
            }

            ci = i, cj = j;
            while(ci >= 0 && ci < n && cj >= 0 && cj < m){
                curr+=a[ci][cj];
                ci--;
                cj++;
            }

            ci = i, cj = j;
            while(ci >= 0 && ci < n && cj >= 0 && cj < m){
                curr+=a[ci][cj];
                ci++;
                cj++;
            }
            curr-=a[i][j]*3;
            res = max(res, curr);
        }
    }

    debug(res);

}

int main(){IO
	int t=1;
	cin>>t;
	while(t--)  
		sol();
}