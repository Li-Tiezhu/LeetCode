/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = 0, curResult = 0;
        for (int i = 0; i < nums.size(); i++) {
            curResult += nums[i];
            if (curResult < 0) {
                curResult = 0;
            }
            if (curResult > result) {
                result = curResult;
            }
        }
        return result;
    }
};
// @lc code=end
