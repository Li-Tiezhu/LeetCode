/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int lastStoneWeightII(vector<int> &stones) {
        int sum_all = 0, sum;
        for (int i = 0; i < stones.size(); i++)
            sum_all += stones[i];
        sum = sum_all / 2;
        vector<int> dp(sum + 1, 0);
        for (int i = 0; i < stones.size(); i++) {
            for (int j = sum; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum_all - dp[sum] - dp[sum];  // NOTE:因为sum_all可能为奇数，一定要这么处理
    }
};
// @lc code=end
