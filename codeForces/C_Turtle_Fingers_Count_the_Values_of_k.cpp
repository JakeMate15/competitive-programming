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
typedef __int128_t i128;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

//cout for __int128_t 
ostream &operator<<(ostream &os, const __int128_t & value){
    char buffer[64];
    char *pos = end(buffer) - 1;
    *pos = '\0';
    __int128 tmp = value < 0 ? -value : value;
    do{
        --pos;
        *pos = tmp % 10 + '0';
        tmp /= 10;
        }while(tmp != 0);
        if(value < 0){
        --pos;
        *pos = '-';
    }
    return os << pos;
}

//cin for __int128_t
istream &operator>>(istream &is, __int128_t & value){
    char buffer[64];
    is >> buffer;
    char *pos = begin(buffer);
    int sgn = 1;
    value = 0;
    if(*pos == '-'){
        sgn = -1;
        ++pos;
    }
    else if(*pos == '+'){
        ++pos;
    }
    while(*pos != '\0'){
        value = (value << 3) + (value << 1) + (*pos - '0');
        ++pos;
    }
    value *= sgn;
    return is;
}

void sol() {
    int64_t A, B, l;
    cin >> A >> B >> l;

    set<int64_t> res;
    int64_t a = A, b = B;
    for (int i = 2; i <= 20 && (a * b <= l); i++) {
        a *= A;
        for (int j = 2; j <= 20 && (a * b <= l); j++) {
            b *= B;

            int64_t k = l / (a * b);
            if (l == k * a * b) {
                res.insert(k);
            }
        }
    }

    cout << sz(res) << "\n";
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