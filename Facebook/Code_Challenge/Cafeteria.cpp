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

long long getMaxAdditionalDinersCount(long long N, long long K, int M, vector<long long> S) {
    ll result = 0LL;

    ll minSeats = K + 1;
    if (M == 0) {
        return N / minSeats + 1;
    }

    sort(S.begin(), S.end());
    

    ll firstChair = S[0];
    ll firstAvailableIndex = (firstChair - 1) - minSeats;
    if (firstAvailableIndex >= 0) {
        result += firstAvailableIndex / minSeats + 1;
    }

    for (int i = 0; i < M - 1; i++) {
        ll leftFreeChair = S[i] + minSeats;
        ll rightFreeChair = S[i + 1] - minSeats;
        ll diffSpace = rightFreeChair - leftFreeChair;
        if (diffSpace >= 0) {
            result += diffSpace / minSeats + 1;
        }
    }

    ll lastChair = S[M - 1];
    ll lastAvailableIndex = (lastChair - 1) + minSeats;
    if (lastAvailableIndex <= N-1) {
        result += (N - 1 - lastAvailableIndex)/ minSeats + 1;
    }

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    //cin>>t;

    ll N, K, M;
    cin >> N >> K >> M;
    vector<ll> a(M);
    for(auto &x: a) {
        cin >> x;
    }


    cout << getMaxAdditionalDinersCount(N, K, M, a) << "\n";

    return 0;
}