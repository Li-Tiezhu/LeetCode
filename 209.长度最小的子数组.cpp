#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 暴力解法-已超时
        // int ret = INT32_MAX, sum = 0, lenCurrent = 0;
        //
        // for (int i = 0; i < nums.size(); i++) {
        //     sum = 0;
        //     for (int j = i; j < nums.size(); j++) {
        //         sum += nums[j];
        //         if (sum >= target) {
        //             lenCurrent = j - i + 1;
        //             ret = ret < lenCurrent ? ret : lenCurrent;
        //             break;
        //         }
        //     }
        // }
        //
        // return ret == INT32_MAX ? 0 : ret;

        // 双指针法（滑动窗口法）
        int left = -1, right = -1, sum = 0, ret = INT32_MAX;
        while (right < nums.size()) {
            if (sum < target) {
                right += 1;
                if (right >= nums.size()) {
                    break;
                }
                sum += nums[right];
            }
            if (sum >= target) {
                if ((right - left + 1) < ret) {
                    ret = right - left + 1;
                }
                sum -= nums[left++];
            }
        }

        return ret == INT32_MAX ? 0 : ret;
    }
};
// @lc code=end
