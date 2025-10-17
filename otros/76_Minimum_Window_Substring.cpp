#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        vector<vector<int>> appearances(n + 1, vector<int>(60));
        for (int i = 1; i <= n; i++) {
            appearances[i][s[i - 1] - 'a']++;
            for (int j = 0; j < 60; j++) {
                appearances[i][j] += appearances[i - 1][j];
            }
        }

        vector<int> pattern(60);
        for (const char &c: t) {
            pattern[c - 'a']++;
        }

        string minimunSubtring = "";
        for (int i = 0; i < n; i++) {
            int start = i - 1, end = n;
            while (start + 1 < end) {
                int mid = (start + end) / 2;
                bool valid = true;
                for (int j = 0; j < 60; j++) {
                    if (appearances[mid + 1][j] - appearances[i][j] < pattern[j]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    end = mid;
                } else {
                    start = mid;
                }
            }

            if (end < n && (minimunSubtring.size() == 0 || end - i + 1 < minimunSubtring.size())) {
                minimunSubtring = s.substr(i, end - i + 1);
            }
        }

        return minimunSubtring;
    }
};

int main () {
    string s, t;
    cin >> s >> t;

    Solution sol;
    cout << sol.minWindow(s, t) << "\n";

    return 0;
}