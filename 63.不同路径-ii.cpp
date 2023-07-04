/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> myMap(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 1) {
                for (int j = i; j < n; j++) {  // NOTE: 后面本来都是0无需重新填充
                    myMap[0][j] = 0;
                }
                break;
            }
            myMap[0][i] = 1;
        }
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1) {
                for (int j = i; j < n; j++) {
                    myMap[i][0] = 0;
                }
                break;
            }
            myMap[i][0] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    myMap[i][j] = 0;
                    continue;
                }
                myMap[i][j] = myMap[i - 1][j] + myMap[i][j - 1];
            }
        }
        return myMap[m - 1][n - 1];
    }
};
// @lc code=end
