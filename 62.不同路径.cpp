/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> myMap(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            myMap[0][i] = 1;
        }
        for (int i = 0; i < m; i++) {
            myMap[i][0] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n ; j++) {
                myMap[i][j] = myMap[i][j - 1] + myMap[i - 1][j];
            }
        }
        return myMap[m - 1][n - 1];
    }
};
// @lc code=end
