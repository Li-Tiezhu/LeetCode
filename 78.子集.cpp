/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> curNum;

    void backstrackingDMSXL(vector<int> &nums, int start) {
        result.push_back(curNum);
        if (start == nums.size()) {
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            curNum.push_back(nums[i]);
            backstrackingDMSXL(nums, start + 1);
            curNum.pop_back();
        }
    }

    void backstracking(vector<int> &nums, int n) {
        if (n == nums.size()) {
            result.push_back(curNum);
            return;
        }

        for (int i = 0; i < 2; i++) {
            if (i == 1) {
                curNum.push_back(nums[n]);
                backstracking(nums, n + 1);
                curNum.pop_back();
            }
            else {
                backstracking(nums, n +1);
            }
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backstracking(nums, 0);
        return result;
    }
};
// @lc code=end
