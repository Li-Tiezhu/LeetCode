/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int findMaxForm_three(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        int zero = count(strs[0].begin(), strs[0].end(), '0');
        int one = strs[0].size() - zero;
        for (int j = zero; j <= m; j++) {
            for (int k = one; k <= n; k++) {
                dp[0][j][k] = 1;
            }
        }
        for (int i = 1; i < strs.size(); i++) {
            zero = count(strs[i].begin(), strs[i].end(), '0');
            one = strs[i].size() - zero;
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    if (j >= zero && k >= one)  // NOTE: 注意这里需要同时放得下(&&)才放或者有一个放不下(||)就保留之前的结果
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - zero][k - one] + 1);
                    else {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                }
            }
        }
        return dp[strs.size() - 1][m][n];
    }

   public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < strs.size(); i++) {
            int zero = count(strs[i].begin(), strs[i].end(), '0');
            int one = strs[i].size() - zero;
            for (int j = m; j >= zero; j--) {
                for (int k = n; k >= one; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - zero][k - one] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
