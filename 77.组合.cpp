/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    // NOTE:无需计数num，只需要知道begin就可以，使用for循环即可避免y数组越界的问题
    void backtrackingMy(int n, int k, int num, int begin,  vector<int> cur) {
        if (num > k) {
            result.push_back(cur);
            return;
        }
        while ((n - begin) >= (k - num)) {
            cur.push_back(begin);
            backtrackingMy(n, k, num + 1, begin + 1, cur);
            cur.pop_back();
            begin++;
        }
    }

    // 代码随想录
    vector<int> curPath;
    void backtracking(int n, int k, int startIndex) {
        if (curPath.size() == k) {
            result.push_back(curPath);
            return;
        }
        // for (int i = startIndex; i <= n; i++) {
        for (int i = startIndex; i <= n - (k - curPath.size()) + 1; i++) { // NOTE: 这里需要加1
            curPath.push_back(i);
            backtracking(n, k, i + 1);  // NOTE:这里是i不是startIndex
            curPath.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        // vector<int> vec;
        // backtrackingMy(n, k, 1, 1, vec);
        backtracking(n, k, 1);
        return result;
    }
};
// @lc code=end
