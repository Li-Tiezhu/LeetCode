/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> curNum;
    int curSum;

    void backstracking(vector<int> &candidates, int target, int start) {
        if (curSum == target) {
            result.push_back(curNum);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] + curSum > target) {
                break;
            }

            curSum += candidates[i];
            curNum.push_back(candidates[i]);
            backstracking(candidates, target, i + 1);
            curSum -= candidates[i];
            curNum.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backstracking(candidates, target, 0);
        return result;
    }
};
// @lc code=end
