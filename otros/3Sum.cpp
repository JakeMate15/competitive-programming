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
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, int> cnt;
        for (auto x: nums) {
            cnt[x]++;
        }

        vector<pair<int, int>> counter(cnt.begin(), cnt.end());
        int n = counter.size();
        vector<vector<int>> triplets;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int target = -1 * (counter[i].first + counter[j].first);
                auto it = lower_bound(counter.begin(), counter.end(), make_pair(target, 0));
                if (it != counter.end() && it->first == target) {
                    triplets.push_back({counter[i].first, counter[j].first, target});
                }
            }
        }

        return triplets;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int xx;
    vector<int> nums;
    while (cin >> xx) {
        nums.push_back(xx);
    }

    Solution s;
    auto ans = s.threeSum(nums);
    for (auto x: ans) {
        for (auto y: x) {
            cout << y << " ";
        }
        cout << "\n";
    }

    return 0;
}