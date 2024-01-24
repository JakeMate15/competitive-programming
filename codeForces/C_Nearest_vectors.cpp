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

const ld eps = 1e-20, inf = numeric_limits<ld>::max(), pi = acos(-1);
bool geq(ld a, ld b){return a-b >= -eps;}     //a >= b
bool leq(ld a, ld b){return b-a >= -eps;}     //a <= b
bool ge(ld a, ld b){return a-b > eps;}        //a > b
bool le(ld a, ld b){return b-a > eps;}        //a < b
bool eq(ld a, ld b){return abs(a-b) <= eps;}  //a == b
bool neq(ld a, ld b){return abs(a-b) > eps;}  //a != b

bool cmp(pair<ld, int> a, pair<ld, int> b) {
    return le(a.first, b.first);
}

void sol(){
    int n;
    cin >> n;

    vector<pair<ld, int>> st(n);
    for (int i = 0; i < n; i++) {
        int x, y; 
        cin >> x >> y;

        ld m;
        if(x == 0) {
          m = pi / 2.0L;
        }
        else{
          m = atan2(1.0L * y, 1.0L * x);
        }

        if(x == 0 && y > 0) m = pi / 2.0L;
        if(x == 0 && y < 0) m = 3.0L * pi / 2.0L;
        if(x > 0 && y == 0) m = 0.0l;
        if(x < 0 && y == 0) m = pi;
        if((x < 0 || x > 0) && y < 0) m += 2.0 * pi;

        st[i] = {m,i + 1};
    }

    sort(all(st), cmp);
    st.push_back(st[0]);
 
    int r1 = 0, r2 = 0;
    ld mn = inf;
 
    for (int i = 1; i <= n; i++) {
        ld dif = min(abs(st[i].first - st[i - 1].first), 2.0L * pi - abs(st[i].first - st[i - 1].first));
        if(le(dif, mn)){
            mn = dif;
            r1 = st[i].second;
            r2 = st[i-1].second;
        }
    }
 
    cout << r1 << " " << r2 << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    setprecision(20);

    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}