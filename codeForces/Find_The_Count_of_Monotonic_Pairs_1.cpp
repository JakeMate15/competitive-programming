#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MX = 2E5 + 5;


const int MOD = 1e9 + 7;
int dp[2001][1001]; 

int solve(int i, int sum1, const vector<int>& nums) {
    if (i == nums.size()) 
        return 1; 
    if (dp[i][sum1] != -1) 
        return dp[i][sum1]; 
    
    int count = 0;
    
    for (int arr1_i = sum1; arr1_i <= nums[i]; ++arr1_i) {
        int arr2_i = nums[i] - arr1_i;
        count = (count + solve(i + 1, arr1_i, nums)) % MOD;
    }
    
    return dp[i][sum1] = count;
}

int countOfPairs(vector<int>& nums) {
    memset(dp, -1, sizeof(dp)); 
    return solve(0, 0, nums); 
}

void sol () {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &x: nums) {
        cin >> x;
    }

    cout << countOfPairs(nums) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    // cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}