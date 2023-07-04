/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        int  min = 0, max = num;
        long long middle;
        while (min <= max) {
            middle = (max + min) / 2;
            if (middle * middle > num) {
                max = middle - 1;
            }
            else if (middle * middle < num) {
                min = middle + 1;
            }
            else {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end

