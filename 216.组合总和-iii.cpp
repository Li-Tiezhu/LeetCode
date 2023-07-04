/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> curPath;
    int curSum = 0;

    void backstracking(int k, int n, int curNum) {
        if (curPath.size() == k) {
            if (curSum == n) {
                result.push_back(curPath);
            }
            return;
        }

        for (int i = curNum; i <= 9 - (k - curPath.size()) + 1; i++) {
            if ((curSum + i) > n) {
                break;
            }
            curSum += i;
            curPath.push_back(i);
            backstracking(k, n, i + 1);
            curSum -= i;
            curPath.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backstracking(k, n, 1);
        return result;
    }
};
// @lc code=end
