//https://codeforces.com/gym/104375/problem/D
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(ll (i)=0; i<n; i++)
#define forr(i,a,n) for(ll i=(a); i<n; i++)
#define fore(i,a,n) for(ll i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define debug(a)    cout << a << "\n"

typedef array<int, 2> ii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ordered_set nums;
int id = 0;

void add(int x) {
    nums.insert({x, id});
    id++;
}
 
void rem(int x) {
    auto it = nums.lower_bound({x, 0});
    if(it == nums.end())
        return;
    nums.erase(it);
}

int main(){IO
    int n,q;cin>>n>>q;

    forn(i,n){
        int l;cin>>l;
        add(l);
    }

    while(q--){
        int t;
        cin >> t;
        if(t == 1) {
            int k;
            cin >> k;
            rem(k);
            add(k);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << nums.order_of_key({b + 1, 0}) - nums.order_of_key({a, 0}) << '\n';
        }
    }
    return 0;
}