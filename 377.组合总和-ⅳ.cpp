/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
#include <limits.h>

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 0; j <= target; j++) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > j || dp[j] > INT_MAX - dp[j - nums[i]])  // NOTE: 相加超出int、重量大于背包
                    continue;
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};
// @lc code=end
