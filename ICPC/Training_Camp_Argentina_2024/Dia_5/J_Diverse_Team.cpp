#include<bits/stdc++.h>
using namespace std;

#define sz(a)   (int) a.size()
#define all(a)  a.begin(), a.end()

typedef pair<int, int> ii;

int main () {
    int n, k;
    cin >> n >> k;

    set<int> st;
    vector<ii> a;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.emplace_back(x, i);

        if (!st.count(x)) {
            res.push_back(i);
            st.insert(x);
        }
    }

    if (sz(res) < k) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    for (auto x: res) {
        if (k > 0) {
            k--;
            cout << x + 1 << " ";
        }
    }

    return 0;
}