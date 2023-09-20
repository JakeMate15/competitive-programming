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

const int mx = 505;
int h, w;
char g[mx][mx];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
 
int ddr[4] = {-1, -1, 1, 1};
int ddc[4] = {-1, 1, 1, -1};

void sol(){
    cin>>h>>w;
    int totnum = 0;
    forn(i,h) {
        cin>>g[i];
        forn(j,w)
            if (g[i][j] == '*') totnum++;
    }
 
    bool ok = false;
    bool checked = false;
    forr(i,1,h-1){
        forr(j,1,w-1){
            bool todos = true;
            forn(k,4)
                if (g[i + dr[k]][j + dc[k]] == '.')
                    todos = false;
 
            if (!todos) continue;
 
            int forma = 0;
 
            int cr = i;
            while (cr >= 0) {
                if (g[cr][j] == '*')
                    cr--, forma++;
                else break;
            }
            cr = i;
            while (cr < h) {
                if (g[cr][j] == '*')
                    cr++, forma++;
                else break;
            }
 
            int cc = j;
            while (cc >= 0) {
                if (g[i][cc] == '*')
                    cc--, forma++;
                else break;
            }
            cc = j;
            while (cc < w) {
                if (g[i][cc] == '*')
                    cc++, forma++;
                else break;
            }
 
            ok = (forma - 3 == totnum);
            checked = true;
            break;
 
        }
 
        if (checked) break;
 
    }
 
    debln((ok?"YES\n":"NO\n"));
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