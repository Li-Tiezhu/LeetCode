/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>nums_jump(nums.size(), 0);
        int cover = 0;
        for (int i = 0; i <= cover; i++) {
            cover = i + nums[i];
            if (cover >= nums.size())
                cover = nums.size() - 1;
            for (int j = 1; i + j < nums.size() && j <= nums[i]; j++) {
                if (nums_jump[i + j] == 0) {
                    nums_jump[i + j] = nums_jump[i] + 1;
                }
                else {
                    if (nums_jump[i + j] > nums_jump[i] + 1) {
                        nums_jump[i + j] = nums_jump[i] + 1;
                    }
                }
            }
        }

        return nums[nums.size() - 1];
    }
};
// @lc code=end
