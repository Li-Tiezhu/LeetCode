/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> curNum;

    void backstracking(vector<int> &nums, int start) {
        result.push_back(curNum);
        if (start == nums.size()) {
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            curNum.push_back(nums[i]);
            backstracking(nums, i + 1);
            curNum.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backstracking(nums, 0);
        return result;
    }
};
// @lc code=end
