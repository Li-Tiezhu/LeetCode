/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int j = g.size() - 1, result = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for (int i = s.size() - 1; i > 0; i++) {
            while (j>=0 && g[j] > s[i]) {
                j--;
            }
            j--;
            result++;
            if (j < 0)
                break;
        }

        return result;
    }
};
// @lc code=end
