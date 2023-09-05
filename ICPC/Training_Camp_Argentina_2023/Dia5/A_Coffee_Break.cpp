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

void sol(){
        int n,m,d;
        cin>>n>>m>>d;

        multiset<int> a;
        map<int,set<int>> s;
        forn(i,n){
                int x;
                cin>>x;
                a.insert(x);
                s[x].insert(i);
        }

        vi res(n);
        int dia = 1;
        while(!a.empty()){
                int x = *a.begin();
                int pos = *s[x].begin();
                a.erase(a.begin());
                s[x].erase(pos);
                res[pos] = dia;

                while(a.upper_bound(x+d)!=a.end()){
                        auto it = a.upper_bound(x+d);
                        x = *it;
                        a.erase(it);
                        pos = *s[x].begin();
                        s[x].erase(pos);
                        res[pos] = dia;
                }
                dia++;
        }

        debug(dia-1);
        for(auto x: res)
                cout << x << " ";

}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}

/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef long double ld;
typedef unsigned long long ull;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<ll> vl;
typedef vector<lli> vli;
typedef vector<double> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define res resize
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ins insert
#define lsb(x) x&(-x)

const ll MOD = 998244353;
const char nl = '\n';
const int MAX = 3e5 + 5;
const double eps = 1e-9;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    i
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

*/