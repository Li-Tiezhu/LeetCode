/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> cur(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < cur[1])
                // NOTE:这里必须要max，因为后一段的终点可能比前一段小
                cur[1] = max(intervals[i][1], cur[1]);
            else {
                result.push_back(cur);
                // NOTE:这里就是直接把这一段变成cur，无需增加到下一段
                cur = vector<int>(intervals[i]);
            }
        }
        result.push_back(cur);
        return result;
    }
};
// @lc code=end
