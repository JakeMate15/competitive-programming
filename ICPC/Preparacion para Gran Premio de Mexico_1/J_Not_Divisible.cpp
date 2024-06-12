#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;

using pi = pair<int,int>;
using pl = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

#define f first
#define s second


typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<bool> vb;

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ins insert

#define rep(i,b) for(int i=0; i<(b); i++)
#define each(a,x) for(auto& a:x)

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

const char nl = '\n';
const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vi total(1e6+1, 0);
    vb mark(1e6+1, 0);
    vi a(n);
    rep(i,n) {
        int x;
        cin >> x;
        a[i] = x;
        total[x]++;
        if(total[x] > 1) continue;
        for(ll i=2*x; i<=1e6; i+=x) {
            mark[i] = 1;
        }
    }

    int ans = n;
    each(x,a) {
        if(mark[x] || total[x] > 1) {
            ans--;
        }
    }

    cout << ans << nl;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}