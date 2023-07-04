/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
#include <iostream>
#include <type_traits>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int result = 1;  // NOTE: 不为空至少需要一支箭，后面是每有一个超出的就加一支

        if (points.size() == 0)
            return 0;
        sort(points.begin(), points.end(), cmp);
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > points[i - 1][1]) {
                result++;
            }
            else {
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
        }

        return result;
    }
};
// @lc code=end
