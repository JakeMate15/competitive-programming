#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl              cout << "\n";
#define u_map           gp_hash_table
#define uid(a, b)       uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

int a[MX], n, q;

int sum(ll n) {
    int res = 0;
    while(n) {
        res += n % 10;
        n /= 10; 
    }

    return res;
}

struct SegmentTree{
	int N;
	vector<int> ST;
 
	//build from an array in O(n)
	SegmentTree(int N): N(N){
		ST.resize(N << 1,0);
	}
 
    void update(int l, int r, int value){
        for (l += N, r += N; l < r; l >>= 1, r >>= 1){
            if (l&1)     ST[l++] += value;
            if (r & 1)   ST[--r] += value;
        }
    }
 
    //Get element at i
    int query(int p){
        int v = 0, pos = p;

        for (p += N; p > 0; p >>= 1) v += ST[p];

        int res = a[pos];
        for(int i = 0; i < v; i++) {
            if(res < 10) {
                break;
            }
            res = sum(res);
        }

        return res;
	}
};

void sol(){
    cin >> n >> q;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    SegmentTree st(n);
    while(q--) {
        int op, x, l, r;
        cin >> op;

        if(op == 1) {
            cin >> l >> r;
            st.update(l - 1, r, 1);
        }
        else{
            cin >> x;
            x--;

            cout << st.query(x) << "\n";
        }
    }


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    cin>>t;

    while(t--){
        sol();
    }

    return 0;
}