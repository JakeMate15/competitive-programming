#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ordered_set ors;
    for(int i = 0; i < k; i++) {
        ors.insert(a[i]);
    }

    for(int i = k - 1; i < n; i++) {
        cout << *ors.find_by_order((k - 1) / 2) << " \n"[i == n - 1];
        ors.erase(ors.upper_bound(a[i - k + 1]));
        ors.insert(a[i + 1]);
    }   
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}