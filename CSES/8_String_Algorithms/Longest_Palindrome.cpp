#include <bits/stdc++.h>
using namespace std;

string preprocess(string s) {
    string t = "^";
    for (char c : s) {
        t += "#" + string(1, c);
    }
    t += "#$";
    return t;
}

string manacher(string s) {
    string T = preprocess(s);
    int n = T.length();
    vector<int> P(n, 0);
    int C = 0, R = 0;
    for (int i = 1; i < n-1; i++) {
        int mirr = 2*C - i;
        if (i < R)
            P[i] = min(R-i, P[mirr]);
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
            P[i]++;
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
    int maxLen = 0, centerIndex = 0;
    for (int i = 1; i < n-1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }
    return s.substr((centerIndex - 1 - maxLen) / 2, maxLen);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    cout << manacher(s) << "\n";
    return 0;
}
