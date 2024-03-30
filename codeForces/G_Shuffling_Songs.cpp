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

struct canc {
    string gen, escritor;
};

int n;
vector<canc> canciones;
vector<vector<int>> memo;

bool ok(const canc& a, const canc& b) {
    return a.gen == b.gen || a.escritor == b.escritor;
}

int go(int idx, vector<bool>& usado, int ult) {
    if (idx == n) {
        return 0;
    }

    if (memo[idx][ult + 1] != -1) return memo[idx][ult + 1];

    int mn = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (!usado[i] && (ult == -1 || ok(canciones[ult], canciones[i]))) {
            usado[i] = true;
            mn = min(mn, go(idx + 1, usado, i));
            usado[i] = false;
        }
    }

    if (ult != -1) {
        mn = min(mn, 1 + go(idx + 1, usado, ult));
    }

    memo[idx][ult + 1] = mn == INT_MAX ? 0 : mn;
    return memo[idx][ult + 1];
}

void sol() {
    cin >> n;
    canciones.resize(n);
    memo.assign(n, vector<int>(n + 1, -1));
    for (int i = 0; i < n; ++i) {
        cin >> canciones[i].gen >> canciones[i].escritor;
    }

    vector<bool> usado(n, false);
    cout << go(0, usado, -1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}
