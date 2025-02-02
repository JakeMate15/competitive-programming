#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), [] (vector<int> a, vector<int> b) {
            if (a.back() == b.back()) {
                return a[0] < b[0];
            }
            return a.back() < b.back();
        });

        vector<int> pref(30);
        for (auto x: nums) {
            pref[x[0]]++;
            pref[x.back() + 1]--;
        }

        for (int i = 1; i < 30; i++) {
            pref[i] += pref[i - 1];
        }

        for (auto x: pref) {
            cerr << x << " ";
        }

        // int number_of_lists = nums.size();

        // if (number_of_lists == 1) {
        //     return {nums[0][0]};
        // }

        // int start = nums[0].back();
        // int end = nums.back().back();
        
        // // The last two intervals intersect
        // if (nums[number_of_lists - 2].back() >= nums.back()[0]) {
        //     for (int i = nums[number_of_lists - 2].size() - 1; i >= 0; i--) {
        //         if (nums[number_of_lists - 2][i] >= nums.back()[0]) {
        //             end = 
        //         }
        //     }
        // } else {
        //     end = nums.back()[0];
        // }

        // if (end < start) {
        //     start = end;
        // }

        // return {start, end};
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int num;
            cin >> num;
            arr[i].push_back(num);
        }
    }

    Solution sol;
    auto r = sol.smallestRange(arr);
    cout << r[0] << " " << r[1] << "\n";

    return 0;
}