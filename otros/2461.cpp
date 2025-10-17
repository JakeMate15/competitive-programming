#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> counter;
        long long currentSum = 0, bestSum = 0;
        for (int i = 0; i < k; i++) {
            counter[nums[i]]++;
            currentSum += nums[i];
        }

        if (counter.size() == k) {
            bestSum = currentSum;
        }

        for (int i = k; i < n; i++) {
            currentSum -= nums[i - k];
            counter[nums[i - k]]--;

            if (counter[nums[i - k]] == 0) {
                counter.erase(nums[i - k]);
            }
            
            currentSum += nums[i];
            counter[nums[i]]++;

            if (counter.size() == k) {
                bestSum = max(bestSum, currentSum);
            } 
        }

        return bestSum;
    }
};

int main () {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    Solution s;
    cout << s.maximumSubarraySum(a, k) << "\n";
}