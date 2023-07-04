/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> curPath;
    // NOTE: 可以使用下面的方式定义，避免空间的浪费
    // vector<bool> falg(nums.size(), false);
    bool flag[6] = {0};

    vector<vector<int>> permute(vector<int>& nums) {
        if (curPath.size() == nums.size()) {
            result.push_back(curPath);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (flag[i] == true) {
                continue;
            }
            flag[i] = true;
            curPath.push_back(nums[i]);
            permute(nums);
            curPath.pop_back();
            flag[i] = false;
        }

        return result;
    }
};
// @lc code=end
