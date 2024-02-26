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

void sol() {
    string s;
    cin >> s;
    ll len = sz(s), maxCeros = -1, aux = 0;
    if(len == 1){
        s[0] == '1' ? (cout << 1 << "\n") : (cout << 0 << "\n");
        return;
    }

    for(int i = 0; i < len; i++) {
        if(s[i] == '1') {
            if(i == len - 1 && s[0] == '1' && aux != len - 1){
                int i = 0;
                while(s[i] == '1'){
                    aux++;
                    i++;
                }
            }
            aux++;
        }
        else{
            maxCeros = max(maxCeros, aux);
            aux = 0;
        }
    }
    maxCeros = max(maxCeros, aux);

    ll res;
    if(maxCeros == 0)           res = 0;
    else if(maxCeros == 1)      res = 1;
    else if(maxCeros == len)    res = len * len;
    else                        res = (maxCeros + 1) / 2 * ceil(1.0 * (maxCeros + 1) /2);

    cout << res << "\n";
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