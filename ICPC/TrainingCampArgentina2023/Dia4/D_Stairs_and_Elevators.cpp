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
#define techo(x,y)   (x%y?x/y+1:x/y)
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"
#define sz(a)       (int)a.size()

const lli MX = 1e18;
const lli MN = -1e18;

set<lli> escalera, elevador;

lli bs(set<lli> &a, lli ov) {
        auto it = a.lower_bound(ov);
        if (it == a.end()) 
                return MX;
        return *it;

}

lli bs2(set<lli> &a, lli ov) {

        if (!a.size()) 
                return -MX;
        auto it = a.lower_bound(ov);
        if (it == a.begin()) 
                return -MX;
        it--;
        return *it;

}

void sol() {
        lli n, m, v, s, e;
        cin>>n>>m;
        cin>>s>>e;
        cin>>v;

        for (int i = 0; i < s; i++) {
                lli lec; cin>>lec;
                escalera.insert(lec);
        }

        for (int i = 0; i < e; i++) {
                lli lec; cin>>lec;
                elevador.insert(lec);
        }

        int q;
        cin>>q;
        while (q--) {

                lli x1, y1, a, b;
                cin>>x1>>y1>>a>>b;

                if (x1 == a) {
                        debug(abs(b - y1));
                        continue;
                }

                lli a1 = bs(escalera, y1);
                lli a2 = bs2(escalera, y1);

                lli res = MX;
                res = min(res, abs(y1 - a1) + abs(b - a1) + abs(x1 - a));
                res = min(res, abs(y1 - a2) + abs(b - a2) + abs(x1 - a));

                a1 = bs(escalera, b);
                a2 = bs2(escalera, b);

                res = min(res, abs(y1 - a1) + abs(b - a1) + abs(x1 - a));
                res = min(res, abs(y1 - a2) + abs(b - a2) + abs(x1 - a));

                a1 = bs(elevador, y1);
                a2 = bs2(elevador, y1);

                res = min(res, abs(y1 - a1) + abs(b - a1) + techo(abs(x1 - a), v));
                res = min(res, abs(y1 - a2) + abs(b - a2) + techo(abs(x1 - a), v));

                a1 = bs(elevador, b);
                a2 = bs2(elevador, b);

                res = min(res, abs(y1 - a1) + abs(b - a1) + techo(abs(x1 - a), v));
                res = min(res, abs(y1 - a2) + abs(b - a2) + techo(abs(x1 - a), v));

                debug(res);

        }
        
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}