#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(n));

        dp[0][0] = nums[0];
        dp[1][0] = nums[0];
        for (int i=1; i<n; i++) {
            dp[0][i] = max(dp[0][i-1]+nums[i], nums[i]);
            dp[1][i] = max(dp[1][i-1], dp[0][i]);
        }

        return dp[1].back();
    }
};