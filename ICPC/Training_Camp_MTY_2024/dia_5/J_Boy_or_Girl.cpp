#include<bits/stdc++.h>
using namespace std;

#define sz(a)   a.size()

int main () {
    int t = 1;
    // cin >> t;

    while (t--) {
        string s;
        cin >> s;

        set<char> st;
        for (auto x: s) {
            st.insert(x);
        }

        if (!(sz(st) & 1)) cout << "CHAT WITH HER!";
        else    cout << "IGNORE HIM!";
    }
}