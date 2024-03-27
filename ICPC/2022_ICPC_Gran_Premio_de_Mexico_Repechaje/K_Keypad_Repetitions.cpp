#include<bits/stdc++.h>
using namespace std;

#define sz(a)   (int)a.size()
#define all(a)  a.begin(), a.end()

typedef long long ll;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;

    vector<int> a = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9 , 9};
    map<string, int> st;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        string ss = "";
        for (auto x: s) {
            ss += to_string(a[x - 'a']);
        }

        st[ss]++;
    }

    while (q--) {
        string s;
        cin >> s;

        cout << st[s] << "\n";
    }
}