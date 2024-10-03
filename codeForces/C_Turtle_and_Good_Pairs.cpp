#include<bits/stdc++.h>
using namespace std;

void sol() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> cnt(26);
    for (auto x: s) {
        cnt[x - 'a']++;
    }

    string res = "";
    while (n) {
        for (int i = 0; i < 26; i++) {
            if (cnt[i]) {
                res += ('a' + i);   
                cnt[i]--;
                n--;
            }
        }
    }

    cout << res << "\n";
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