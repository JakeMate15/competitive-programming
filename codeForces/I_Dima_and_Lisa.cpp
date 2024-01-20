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

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

bool primo(ll n) {
    if(n < 2)   return false;

    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

void sol() {
    int n;
    cin >> n;

    if(primo(n)) {
        cout << 1 << "\n";
        cout << n << "\n";
    }
    else if(primo(n - 2)) {
        cout << 2 << "\n";
        cout << 2 << " " << n - 2 << "\n";
    }
    else {
        cout << 3 << "\n";
        for(int i = 3; i <= n; i += 2) {
            for(int j = 3; j <= n; j += 2) {
                if(primo(i) && primo(j) && primo(n - i - j)) {
                    cout << i << " " << j << " " << n - i - j << "\n";
                    return;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}