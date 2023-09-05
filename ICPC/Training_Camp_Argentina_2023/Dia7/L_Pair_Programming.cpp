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

const int mx = 100+5;
int a[mx],b[mx];

void sol(){
        int k,n,m;
        cin>>k>>n>>m;

        forn(i,n)
                cin>>a[i];

        forn(i,m)
                cin>>b[i];

        int p1=0,p2=0;
        bool bandera = true;
        vi res;

        while (p1 < n || p2 < m) {
                if (p1 < n && a[p1] == 0) {
                        p1++;
                        res.push_back(0);
                        k++;
                        continue;
                }
                if (p2 < m && b[p2] == 0) {
                        p2++;
                        res.push_back(0);
                        k++;
                        continue;
                }

                if (p1 < n && a[p1] <= k) {
                        res.push_back(a[p1]);
                        p1++;
                }
                else if (p2 < m && b[p2] <= k) {
                        res.push_back(b[p2]);
                        p2++;
                }
                else {
                        bandera = false;
                        break;
                }
        }

        if (!bandera) {
                debug(-1);
                return;
        }
        for (auto i : res)
                cout << i << " ";
        
        debug("");
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}