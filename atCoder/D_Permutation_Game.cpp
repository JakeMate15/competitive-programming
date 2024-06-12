#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(v)          v.begin(), v.end()
#define rall(v)         v.rbegin(), v.rend()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

ll get (vector<ll> arr, vector<ll> p, int pos, int k) {
    ll puntos = 0;

    vector<bool> vis(sz(arr) + 1);
    int curr = pos, i = 1;
    ll s = 0;

    while (!vis[curr] && k - i >= 0) {
        vis[curr] = true;

        s += arr[curr];
        puntos = max(puntos, s + max(0LL, 1LL * k - i++) * arr[curr]);
        curr = p[curr];
    }

    return puntos;
}

void sol() {
    int n, b, s, k;
    cin >> n >> k >> b >> s;

    vector<ll> arr(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    ll bb = get(arr, p, b, k);
    ll ss = get(arr, p, s, k);

    if (bb == ss) 
        cout << "Draw\n";
    else if (bb > ss) 
        cout << "Bodya\n";
    else
        cout << "Sasha\n";
    
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

// -Wall -Wextra -Wshadow -D_GLIBCXX_ASSERTIONS -DDEBUG -ggdb3 -fmax-errors=2