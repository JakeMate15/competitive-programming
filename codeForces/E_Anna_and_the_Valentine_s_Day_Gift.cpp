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

int ceros(const string& s) {
    int cnt = 0;

    for (int i = s.length() - 1; i >= 0 && s[i] == '0'; --i) {
        cnt++;
    }

    return cnt;
}

struct cmp {
    bool operator()(const string& a, const string& b) const {
        return ceros(a) > ceros(b);

    }
};

string quitaC(string s) {
    auto it = find_if(s.begin(), s.end(), [](unsigned char ch) {
        return ch != '0' && !isspace(ch);
    });

    s.erase(s.begin(), it);

    return s;
}

void sol() {
    int n, m;
    cin >> n >> m;

    multiset<string, cmp> st;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        st.insert(s);
    }

    int turno = 1;
    while (sz(st) >= 2) {
        if (turno) {
            string s = *st.begin();
            st.erase(st.begin());
            reverse(all(s));
            st.insert(quitaC(s));
        }
        else {
            auto it1 = st.begin();
            string s1 = *it1;
            st.erase(it1);
            auto it2 = prev(st.end());
            string s2 = *it2;
            st.erase(it2);

            st.insert(s1 + s2);
        }

        turno ^= 1;
    }

    string s = *st.begin();
    reverse(all(s));
    s = quitaC(s);

    cout << (sz(s) - 1 >= m ? "Sasha" : "Anna") << "\n";
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