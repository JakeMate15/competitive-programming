#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()
#define sz(a)   (int)a.size()
typedef long long ll;

const int mod = 1E9 + 7;
const int MX = 1E5 + 5;

void sol () {
    int n;
    cin >> n;

    string res(n, '0');
    vector<pair<int, string>> arr(n);
    map<string, int> st;

    for (int i = 0; i < n; i++) {
        cin >> arr[i].second;
        arr[i].first = i;
        st[arr[i].second]++;
    }

    sort(all(arr), [] (pair<int, string> a, pair<int, string> b) {
        return sz(a.second) > sz(b.second);
    });

    for (int i = 0; i < n; i++) {
        string ss = arr[i].second;
        int tam = sz(ss);
        for (int j = 1; j <= tam - 1; j++) {
            string s1 = ss.substr(0, j), s2 = ss.substr(j);

            if (st.count(s1) && st.count(s2)) {
                res[arr[i].first] = '1';
            }
            // if (s1 == s2) {
            //     if (st[s1] >= 2) {
            //         res[arr[i].first] = '1';
            //     }
            // }
            // else {
            //     if (st.count(s2) && st.count(s1)) {
            //         res[arr[i].first] = '1';
            //     }
            // }
        }
    }


    cout << res << "\n";
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; 
    cin >> t;

    while (t--) {
        sol();
    }

    return 0;
}


