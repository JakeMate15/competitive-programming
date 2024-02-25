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
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    bool emod = false;

    int uno=0, dos=0, tres=0;

    int ans = 0;
    tres=a[0]/3;
    if(a[0]%3==1)
        uno++;
    else if(a[0] == 2)
        dos++;    

    for (int i = 1; i < n; i++) {
        if(a[i]%3-dos==1)
        {
            dos++;
            if(dos>=1 && uno>=1)
                tres--;
        }
        if(a[i]%3-dos==-1)
        {
            uno++;
            if(dos>=1 && uno>=1)
                tres--;
        }

    }
    cout<<uno+dos+tres;nl
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