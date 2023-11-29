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

/*
3 7 5 1 10 3 20
1 3 3 5 7 10 20

3 7 5 1 10 3 20
1 3 3 5 7 10 20
*/

void sol(){
    int n, i, aux, k;
    cin >> n >> k;
    vector<int> a;

    for(i = 0; i < n; i++){
        cin >> aux;
        a.push_back(aux);
    }
    sort(a.begin(), a.end());
    if(k == 0){
        cout << ((a[0] == 1) ? -1 : a[0]-1) << endl;
    }
    else if(k == n){
        cout << a[n-1] << endl;
    }
    else{
        if(a[k] > a[k-1]){
            cout << a[k-1] << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
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