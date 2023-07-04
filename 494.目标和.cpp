/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // left - right = target
        // left + right = sum
        // right = sum -left
        // left - (sum -left) = target
        // 2*left - sum = target
        // left = (sum + target) / 2
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if ((sum + target) % 2 != 0)
            return 0;
        if (abs(target) > sum)
            return 0;
        sum = (sum + target) / 2;

        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = sum; j >= nums[i]; j--) {
                dp[j] = dp[j] + dp[j - nums[i]];
            }
        }
        return dp[sum];
    }
};
// @lc code=end
