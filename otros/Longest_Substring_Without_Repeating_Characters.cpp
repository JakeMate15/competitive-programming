#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "/algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int ans = 1, start = 0;
        vector<int> last(27, -1);
        for (int i = 0; i < n; i++) {
            start = max(start, last[s[i] - 'a'] + 1);
            last[s[i] - 'a'] = i;
            ans = max(ans, i - start + 1); 
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << "\n";

    return 0;
}