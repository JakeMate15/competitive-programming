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
#define sz(a)           (lli)a.size()

const int mx = 1123;
lli d[mx][mx];
                
void sol(){
        lli n, m, i, j, k, x, y;
        string s, t;
        cin >> s >> t;
        if(sz(s) != sz(t)){
                debug(-1);
                return;
        }
        forn(i,26)
                forn(j,26)
                        d[i][j] = 1e9;
        forn(i,26)
                d[i][i] = 0;
        cin >> n;
        fore(i,1,n){
                char x, y;
                lli z;
                cin >> x >> y >> z;
                x -= 97;
                y -= 97;
                d[x][y] = min((lli)z, d[x][y]);
        }
        forn(i,26)
                forn(j,26)
                        forn(k,26)
                                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
        lli ans = 0;
        forn(i,sz(s)){
                lli x = s[i] - 97;
                lli y = t[i] - 97;
                lli t = 1e12 + 7, id = -1;
                forn(j,26)
                {
                        if(t > d[x][j] + d[y][j])
                        {
                                t = d[x][j] + d[y][j];
                                id = j;
                        }
                }
                ans += t;
                s[i] = id + 97;
        }
        if(ans >= 1e9)
                ans = -1;
        debug(ans);
        if(ans != -1)
                debug(s);
}

int main(){IO
                int t=1;
                //cin>>t;
                while(t--)  sol();
}

