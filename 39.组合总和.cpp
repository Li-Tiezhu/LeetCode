/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int curSum = 0;
    vector<vector<int>> result;
    vector<int> curNum;
    void backstracking(vector<int> &candidates, int target, int start) {
        if (curSum == target) {
            result.push_back(curNum);
            return;
        }
        if (curSum > target) {
            return;
        }

        for (int i = start; (i < candidates.size()) && (curSum + candidates[i] <= target); i++) {
            curSum += candidates[i];
            curNum.push_back(candidates[i]);
            backstracking(candidates, target, i);
            curSum -= candidates[i];
            curNum.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // NOTE:通过排序后在for循环中进行剪枝
        sort(candidates.begin(), candidates.end());
        backstracking(candidates, target, 0);
        return result;
    }
};
// @lc code=end
