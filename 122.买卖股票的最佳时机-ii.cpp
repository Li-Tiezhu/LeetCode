/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1)
            return 0;
        int result = 0, cur;
        for (int i = 1; i < prices.size(); i++) {
            cur = prices[i] - prices[i - 1];
            if (cur > 0) {
                result += cur;
            }
        }

        return result;
    }
};
// @lc code=end
