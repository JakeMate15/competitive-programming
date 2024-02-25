#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

int n,m;
int a[1030][1030],st[2*1030][2*1030];

int op(int a, int b) {
    return a + b;
}
void build(){
    fore(i,0,n)fore(j,0,m)st[i+n][j+m]=a[i][j];
    fore(i,0,n)for(int j=m-1;j;--j)
        st[i+n][j]=op(st[i+n][j<<1],st[i+n][j<<1|1]);
    for(int i=n-1;i;--i)fore(j,0,2*m)
        st[i][j]=op(st[i<<1][j],st[i<<1|1][j]);
}
void upd(int x, int y, int v){
    st[x+n][y+m]=v;
    for(int j=y+m;j>1;j>>=1)st[x+n][j>>1]=op(st[x+n][j],st[x+n][j^1]);
    for(int i=x+n;i>1;i>>=1)for(int j=y+m;j;j>>=1)
        st[i>>1][j]=op(st[i][j],st[i^1][j]);
}
int query(int x0, int x1, int y0, int y1){
    int r=0;
    for(int i0=x0+n,i1=x1+n;i0<i1;i0>>=1,i1>>=1){
        int t[4],q=0;
        if(i0&1)t[q++]=i0++;
        if(i1&1)t[q++]=--i1;
        fore(k,0,q)for(int j0=y0+m,j1=y1+m;j0<j1;j0>>=1,j1>>=1){
            if(j0&1)r=op(r,st[t[k]][j0++]);
            if(j1&1)r=op(r,st[t[k]][--j1]);
        }
    }
    return r;
}


void sol() {
    cin >> n;
    m = n;

    memset(st,0,sizeof(st));

    string op;
    while (cin >> op) {
        int x1, y1, x2, y2;
        ll v;

        if (op == "SET") {
            cin >> x1 >> y1 >> v;
            // x1 += 2, y1 += 2;

            // cerr << op << " " << x1 << " " << y1 << " " << v << "\n";
            // update(x1, y2, v);
            upd(x1, y1, v);
        }
        else if (op == "SUM") {
            int x0,y0,x1,y1;
            cin >> x0 >> y0 >> x1 >> y1;
            x1++;y1++;
            cout << query(x0,x1,y0,y1) << "\n";
            // cout << query(x1, y1, x2, y2) << "\n";
        }
        else {
            break;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}