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

void sol(){
    int n, m, k;
    cin >> n >> m >> k;

    int meta = k / 2, x;

    set<int> a, b;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < m; i++) {
        cin >> x;
        b.insert(x);
    }

    int cntA = 0, cntB = 0, cntAux = 0, cntBaux = 0;
    for (int i = 1; i <= k; i++) {
        if (a.count(i) && !b.count(i)) {
            cntA++;
        }
        else if (!a.count(i) && b.count(i)) {
            cntB++;
        }
        else if (a.count(i) && b.count(i)) {
            cntAux++, cntBaux++;
        }
    }

    if (cntA >= meta && cntB >= meta) {
        cout << "YES\n";
    }
    else {
        int necA = max(0, meta - cntA);
        int posA = (cntAux >= necA ? necA : 0);
        cntA += posA;
        cntAux -= posA;

        int necB = max(0, meta - cntB);
        int posB = (cntAux >= necB ? necB : 0);
        cntB += posB;

        if (cntA >= meta && cntB >= meta) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
        
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}