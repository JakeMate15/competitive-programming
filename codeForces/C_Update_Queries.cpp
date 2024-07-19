#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        int n, m;
        string s1, s2;
        map<int, int> cnt;

        cin >> n >> m >> s1;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        cin >> s2;

        sort(s2.begin(), s2.end());

        int lo = 0, hi = m - 1;
        for (auto &[v, r]: cnt) {
            int i = v - 1;
            while (r--) {
                if (r == 0) {
                    s1[i] = s2[lo++];
                }
                else {
                    s1[i] = s2[hi--];
                }
            }
        }

        cout << s1 << "\n";
    }

    return 0;
}