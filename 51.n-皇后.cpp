/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include <ios>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    vector<string> curPath;

    void backtracking(int n, int curNum, vector<int> &column, vector<int> &left, vector<int> &right) {
        if (curNum == n) {
            result.push_back(curPath);
        }

        for (int i = 0; i < n; i++) {
            string str(n, ',');
            if (column[i] != 0 || left[curNum + i] != 0 || right[i - curNum + n - 1] != 0) {
                continue;
            }
            column[i] = 1;
            left[i + curNum] = 1;
            right[i - curNum + n -1] = 1;
            str[i] = 'Q';
            curPath.push_back(str);
            backtracking(n, curNum + 1, column, left, right);
            curPath.pop_back();
            column[i] = 0;
            left[i + curNum] = 0;
            right[i - curNum + n -1] = 0;

        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> column(n);
        vector<int> left(2 * n - 1);
        vector<int> right(2 * n - 1);
        backtracking(n, 0, column, left, right);
        return result;
    }
};
// @lc code=end
