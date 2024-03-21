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

const ll MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

int to[MAXN][27], term[MAXN], sz[MAXN], link_array [MAXN], next_term[MAXN], cur = 1;
ll dp[MAXN];
 
void add(string &s, int id = 0, int ps = 0) {
	assert(id >= 0 && id < MAXN);
    if(ps == sz(s)) {
        term[id] = 1;
        sz[id] = sz(s);
        return;
    }

    if(!to[id][s[ps] - 'a']) {
        to[id][s[ps] - 'a'] = cur;
        cur++;
    }
    add(s, to[id][s[ps] - 'a'], ps + 1);
}
 
void build_aho() {
    queue<int> q({0});
    next_term[0] = 0;
    while(sz(q)) {
        int u = q.front();
        q.pop();
        for(int ch = 0; ch < 26; ch++) {
            int v = to[u][ch];
            if(v != 0) {
                link_array [v] = (u ? to[link_array [u]][ch] : 0);
                next_term[v] = (term[link_array [v]] ? link_array [v] : next_term[link_array [v]]);
                q.push(v);
            }
            else {
                to[u][ch] = (u ? to[link_array [u]][ch] : 0);
            }
        }
    }
}

void sol(){
    string s;
    cin >> s;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string ss;
        cin >> ss;
        add(ss);
    }

    build_aho();
    /*for(int i = 0; i < cur; i++) {
        cerr  << "id = " << i << " " << link_array [i] << endl;
    }*/

    n = sz(s);

    dp[0] = 1;
    int curr = 0;
    
    for(int i = 1; i <= n; i++) {
        char c = s[i - 1];
        curr = to[curr][c - 'a'];
        int tmp = curr;
        while(tmp > 0) {
            if(term[tmp])
                dp[i] = (dp[i] + dp[i - sz[tmp]]) % MOD;
            tmp = next_term[tmp];
        }
    }
    cout << dp[n] << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    //cin>>t;

    while(t--){
        sol();
    }

    return 0;
}