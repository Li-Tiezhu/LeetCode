#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int> (n));
        int num = 0, line = 0, i = 0, j = 0;

        while (line < n) {
            i = line;
            j = line;
            while(j <= n - line - 2) {
                num++;
                ret[i][j] = num * num;
                j++;
            }
            while (i <= n - line - 2) {
                num++;
                ret[i][j] = num * num;
                i++;
            }
            j--;
            while (j >= line + 1) {
                num++;
                ret[i][j] = num * num;
                j--;
            }
            i--;
            while(i <= line + 1) {
                num++;
                ret[i][j] = num * num;
                i--;
            }

            line++;
        }

        return ret;
    }
};
// @lc code=end
