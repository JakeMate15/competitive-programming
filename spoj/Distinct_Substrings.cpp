#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

struct state {
    int len, link;
    map<char, int> next;
};

struct SAM {
    vector<state> st;
    vector<bool> vis;
    vector<ll> dp;
    int sz = 0, last;

    SAM (string s) {
        int n = s.size() * 2 + 5;
        st.resize(n);
        vis.resize(n);
        dp.resize(n);

        st[0].len = 0;
        st[0].link = -1;
        sz++;
        last = 0;

        for (auto x: s) {
            sa_extend(x);
        }
    }

    void sa_extend(char c) {
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        int p = last;
        while (p != -1 && !st[p].next.count(c)) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if (p == -1) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = sz++;
                st[clone].len = st[p].len + 1;
                st[clone].next = st[q].next;
                st[clone].link = st[q].link;
                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }

    ll get_diff_strings(){
        ll tot = 0;
        for(int i = 1; i < sz; i++) {
            tot += st[i].len - st[st[i].link].len;
        }
        return tot;
    }

    void dfs(int nodo, int padre) {
        // cerr << nodo << "\n";
        if (vis[nodo]) return;

        vis[nodo] = true;
        for (auto [c, pos]: st[nodo].next) {
            // cerr << c << " " << pos << "\n";
            // cerr << nodo << " " << pos << " " << c << "\n";
            dfs(pos, nodo);
            dp[nodo] += (dp[pos] + 1);
        }
    }
};

void sol() {
    string s;
    cin >> s;

    SAM sa(s);

    sa.dfs(0, -1);

    cout << sa.dp[0] << "\n";

    // dfs(0, -1);
    // cout << sz(aux) << "\n";
    // cout << dp[0] << " " << cnt1 << "\n";
    // cout << get_diff_strings() << " " << cnt2 << "\n";
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