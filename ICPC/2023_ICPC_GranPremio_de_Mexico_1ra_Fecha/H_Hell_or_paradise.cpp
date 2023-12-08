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

int to[MAXN][26], term[MAXN], sz[MAXN], link[MAXN], next_term[MAXN], cur = 1;
ll dp[MAXN];
 
void add(string &s, int id = 0, int ps = 0) {
    if(ps == s.size()) {
        term[id] = 1;
        sz[id] = s.size();
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
    while(q.size()) {
        int u = q.front();
        q.pop();
        for(int ch = 0; ch < 26; ch++) {
            int v = to[u][ch];
            if(v != 0) {
                link[v] = (u ? to[link[u]][ch] : 0);
                next_term[v] = (term[link[v]] ? link[v] : next_term[link[v]]);
                q.push(v);
            }
            else {
                to[u][ch] = (u ? to[link[u]][ch] : 0);
            }
        }
    }
}

void sol(){
	int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        add(s);
    }

    build_aho();
    /*for(int i = 0; i < cur; i++) {
        cerr  << "id = " << i << " " << link[i] << endl;
    }*/

    string s;
    cin >> s;
    n = s.size();

    dp[0] = 1;
    int cur = 0;
	
    for(int i = 1; i <= n; i++) {
        char c = s[i - 1];
        cur = to[cur][c - 'a'];
        //cerr << "act = " << cur << '\n';
        int tmp = cur;
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