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

void Insertar(vector<pair<int, int>> &g, int p, int h){
    if(g[p].first==0)
        g[p]={h, abs(p-h) + g[h].second};
        else if()
}

void solve() {
    int n;
    cin>>n;
    vector<pair<int, int>>g(n, {0, 0});
    while(1){
        char ins;
        int p, h;
        cin>>ins;
        if(ins == 'E'){
            cin>>p;
            cout<<g[p].second;nl    
        }else if(ins == 'I'){
            cin>>p>>h;
            Insertar(g, p, h);
            else

        }
        else if(ins == '0') break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t;
    cin>>t;
    while(t--) {
        solve();
    }

    return 0;
}