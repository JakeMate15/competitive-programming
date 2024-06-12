#include<bits/stdc++.h>

using namespace std;
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()

void sol() {
    int n;
    cin >> n;

    bool f = false;
    vector<string> arr(n);
    for (auto &x: arr) {
        cin >> x;

        string aux = x;
        reverse(all(aux));

        f |= (aux == x);
    }

    if (f) {
        cout << "YES\n";
        return;
    }

    set<string> st;
    for (auto x: arr) {
        int t = sz(x);

        string aux = x;
        reverse(all(aux));

        if (st.count(aux) > 0) {
            cout << "YES\n";
            return;
        }

        if (t == 3) {
            // string s1 = x.substr(0, 2);
            string s2 = x.substr(1, 2);
            reverse(all(s2));

            // string ss1 = s1;
            // reverse(all(ss1));
            // string ss2 = s2;
            // reverse(all(ss2));

            // if (st.count(ss2)) {
            //     cout << "YES\n";
            //     return;
            // }

            // st.insert(s1);
            // st.insert(s2);

            if (st.count(s2)) {
                cout << "YES\n";
                return;
            }
        }
        else {
            auto it = st.lower_bound(aux + "a");
            if (it != st.end()) {
                if ((*it).substr(0, 2) == aux) {
                    cout << "YES\n";
                    return;
                }
            }
        }

        st.insert(x);
    }


    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}