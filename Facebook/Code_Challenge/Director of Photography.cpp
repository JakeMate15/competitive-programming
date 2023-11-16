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

long long getArtisticPhotographCount(int N, string C, int X, int Y) {
    ll ans = 0LL;
    vector<ll> bL(N), bR(N), actorsL(N), actorsR(N);

    bL[0] = C[0] == 'B' ? 1 : 0;
    for(int i = 1; i < N; i++) {
        bL[i] = C[i] == 'B' ? 1 : 0;
        bL[i] += bL[i - 1];
    }

    bR[N - 1] = C[N - 1] == 'B' ? 1 : 0;
    for(int i = N - 2; i >= 0; i--) {
        bR[i] = C[i] == 'B' ? 1 : 0;
        bR[i] += bR[i + 1];
    } 

    for(int i = 0; i < N; i++) {
        int ll = min(N - 1, i + X - 1), rr = min(N - 1, i + Y);
        actorsL[i] = C[i] == 'A' ? bL[rr] - bL[ll]: 0;
        actorsL[i] += i ? actorsL[i - 1] : 0;
    }

    for(int i = N - 1; i >= 0; i--) {
        int rr = max(0, i - X + 1), ll = max(0, i - Y);
        actorsR[i] = C[i] == 'A' ? bR[ll] - bR[rr] : 0;
        actorsR[i] += i == N - 1 ? 0: actorsR[i + 1];
    }

    for(int i = 0; i < N; i++) {
        int ll = min(N - 1, i + X - 1), rr = min(N - 1, i + Y);
        ans += C[i] == 'P' ? actorsL[rr] - actorsL[ll] : 0;
    }

    for(int i = N - 1; i >= 0; i--) {
        int rr = max(0, i - X + 1), ll = max(0, i - Y);
        ans += C[i] == 'P' ? actorsR[ll] - actorsR[rr] : 0;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int n, x, y;
    string s;
    cin >> n >> s >> x >> y;
    cout << getArtisticPhotographCount(n, s, x, y) << "\n";

    return 0;
}