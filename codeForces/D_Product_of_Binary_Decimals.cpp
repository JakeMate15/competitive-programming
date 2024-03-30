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


vector<int> bins;
map<ll, ll> factoriza(ll x) {
    map<ll, ll> res;
    for(ll p: bins) {
        if(p * p > x) {//Cuidado con el overflow, cambiar el tipo a la criba si es necesario
            break;
        }
        int e = 0;
        while(x % p == 0) {
            e++;
            x /= p;
        }

        if(e) {
            res[p] = e;
        }
    }
    
    if(x > 1) {//revisar los limites
        res[x] = 1;
    }

    return res;
}

bool bin(ll n) {
    if (n == 1) return true;

    while (n > 0) {
        if (n % 10 != 0 && n % 10 != 1) return false;
        n /= 10;
    }
    return true;
}


void sol() {
    int n;
    cin >> n;

    if (bin(n)) {
        cout << "YES\n";
        return;
    }

    auto f = factoriza(n);
    for (auto [p, pp]: f) {
        if (!bin(p)) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    int cnt = 0;
    for (int i = 2; i <= 1E5; i++) {
        if (bin(i)) {
            bins.push_back(i);
        }
    }

    while(t--) {
        sol();
    }

    return 0;
}