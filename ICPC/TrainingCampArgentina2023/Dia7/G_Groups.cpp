#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

const int mx = 1000+5;
int a[mx][5];

void sol(){
        int n;
        cin>>n;

        forn(i,n){
                forn(j,5){
                        cin>>a[i][j];
                }
        }

        bool res = false;

        forn(i,5){
                forr(j,i+1,5){
                        int uno = 0, dos = 0;
                        bool bandera = true;
                        forn(k,n){
                                if(!a[k][i] && !a[k][j])
                                        bandera = false;
                                if(a[k][i] && !a[k][j])
                                        uno++;
                                if(a[k][j] && !a[k][i])
                                        dos++;
                        }

                        if(!bandera)
                                continue;
                        if(uno <= n/2 && dos<=n/2)
                                res = true;
                }
        }

        if(res) YES;
        else    NO;
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}