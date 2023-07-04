#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 双指针法
        int idx = 0;
        for (auto x : nums) {  // 和下面迭代器等同
            if (x != val) {
                nums[idx++] = x;
            }
        }
        // for (vector<int>::iterator x = nums.begin(); x != nums.end(); ++x) {
        //     if (*x != val) {
        //         nums[idx++] = *x;
        //     }
        // }
        return idx;

        // 相向双指针法
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            while (left <= right && nums[left] != val) {
                left++;
            }
            while (left <= right && nums[right] == val) {
                right--;
            }
            if (left < right) {
                nums[left++] = nums[right--];
            }
        }
        return left;
    }
};
// @lc code=end
