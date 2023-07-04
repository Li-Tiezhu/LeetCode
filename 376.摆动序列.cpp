/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        int flag = 0, result = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                if (flag == -1) {
                    result++;
                }
                flag = 1;
            }
            else if (nums[i] < nums[i -1]) {
                if (flag == 1) {
                    result++;
                }
                flag = -1;
            }
        }
        if (flag != 0)
            result+=1;

        return result;
    }
};
// @lc code=end
