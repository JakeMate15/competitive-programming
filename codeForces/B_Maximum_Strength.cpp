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

void sol(){
    string s1, s2;
    cin >> s1 >> s2;
    
    int len1 = sz(s1), len2 = sz(s2);
    
    if (len1 < len2) {
        s1 = string(len2 - len1, '0') + s1;
    }
    
    ll res = 0;
    len1 = sz(s1), len2 = sz(s2);
    for (int i = 0; i < len1; i++) {
        int c1, c2;
        c1 = s1[i] - '0';
        c2 = s2[i] - '0';
 
        if(abs(c1 - c2) == 0) {
            continue;
        }
 
        res += abs(c1 - c2);
        i++;
        for(; i < len1; i++) {
            res += 9;
        }
    }
 
    cout << res << "\n";
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