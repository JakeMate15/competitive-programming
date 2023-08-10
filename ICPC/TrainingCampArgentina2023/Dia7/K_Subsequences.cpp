#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(int i=(a); i<n; i++)
#define fore(i,a,n) for(int i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

const int mx = 1e5+10;
int a[mx];
ll f[mx][13];
ll bit[mx][13];
void add(int p, int t, ll val) {
	for (; p < mx; p += p & -p) bit[p][t] += val;
}

ll get(int p, int t) {
	ll res = 0;
	for (; p > 0; p -= p & -p) res += bit[p][t];
	return res;
}

void sol(){
        int n,k;
        cin>>n>>k;


        forn(i,n){
                cin>>a[i];
                f[i][1] = 1;
        }

        forn(i,n){
                forr(j,2,13){
                        add(a[i],j-1,f[i][j-1]);
                        f[i][j] = get(a[i]-1,j-1);
                }
        }

        ll res = 0;
        forn(i,n){
                res+=f[i][k+1];
        }
        debug(res);

}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}