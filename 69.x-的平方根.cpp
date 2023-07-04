/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int min = 0, max = x, middle, ret;
        long long middle_2 = 0;
        while (min <= max) {
            middle = (max + min) / 2;
            middle_2 = middle * middle;
            if (middle_2 <= x) {
                ret = min;
                min = middle + 1;
            }
            else {
                max = middle - 1;
            }
        }

        return ret;
    }
};
// @lc code=end
