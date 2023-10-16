#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define forn(i,n)       for(int i=0; i<n; i++)
#define forr(i,a,n)     for(int i=a; i<n; i++)
#define fore(i,a,n)     for(int i=a; i<=n; i++)
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl              cout << "\n";
#define u_map           gp_hash_table
#define uid(a, b)       uniform_int_distribution<int>(a, b)(rng)

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int mx = 2e5 + 5;

void sol(){
    multiset<int> nums;
    forn(i, 3) {
        int x;
        cin >> x;
        nums.insert(x);
    }

    forn(i, 3) {
        auto it = prev(nums.end());
        if(*it == *nums.begin()) {
            break;
        }
     
        int p = *nums.begin();
        int a1 = *it - p;
        int a2 = *it - a1;
        nums.erase(it);
        nums.insert(a1);
        nums.insert(a2);
    }

    int prim = *nums.begin();
    for(auto x: nums) {
        if(x != prim) {
            debln("NO");
            return;
        }
    }

    debln("YES");
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    cin>>t;

    while(t--){
        sol();
    }

    return 0;
}