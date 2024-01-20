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

vector<int> a;

void sol(){
    int n;
    cin >> n;

    cout << a[n] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    a.push_back(0);
    int i = 1;
    while(sz(a) <= 1000) {
        if(i % 10 == 3 || i % 3 == 0) {

        }
        else {
            a.push_back(i);
        }
        i++;
    }

    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}