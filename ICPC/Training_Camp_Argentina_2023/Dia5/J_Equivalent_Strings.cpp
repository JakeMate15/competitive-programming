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
#define sz(a)       (int)a.size()

const int mx = 200200;
char a[mx],b[mx];
int n;

vi eq(int l, int r, char * s) {
        vi res;
        fore(i,'a','z')
                res.push_back(0);
        fore(i,l,r)
                res[s[i]-'a']++;
        return res;
}

bool sol(int la, int ra, int lb, int rb) {

        if (eq(la, ra, a) != eq(lb, rb, b))
                return false;

        bool iguales = true;
        fore(i,la,ra) {
                if (a[i] != b[lb + i - la])
                        iguales = false;
        }

        if (iguales) 
                return true;
        if (la == ra) 
                return false;

        if ((ra - la + 1) % 2) 
                return false;

        int ma = (la + ra) / 2;
        int mb = (lb + rb) / 2;

        if (sol(la, ma, lb, mb) && sol(ma + 1, ra, mb + 1, rb))
                return true;

        if (sol(la, ma, mb + 1, rb) && sol(ma + 1, ra, lb, mb))
                return true;

        return false;
        
}

int main(){IO
        scanf("%s", a);
        scanf("%s", b);
        n = strlen(a);

	printf(sol(0, n-1, 0, n-1) ? "YES\n":"NO\n");
}