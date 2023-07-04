#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
             while (left < right) {
                // 这些判断都可以在第一次插入不重复元素之后操作
                // if (left > i + 1 && nums[left] == nums[left - 1]) {
                //     left++;
                //     continue;
                // }
                // if (right < nums.size() - 1 && nums[right] == nums[right + 1]) {
                //     right--;
                //     continue;
                // }
                // if ((nums[i] + nums[left] + nums[right]) == 0) {
                //     result.push_back({nums[i], nums[left], nums[right]});
                //     left++;
                //     right--;
                // }
                // else if ((nums[i] + nums[left] + nums[right]) < 0) {
                //     left++;
                // }
                // else {
                //     right--;
                // }


                // 代码随想录简洁方法
                if ((nums[i] + nums[left] + nums[right]) == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (right > left && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    while (right > left && nums[left + 1] == nums[left]) {
                        left++;
                    }
                    left++;
                    right--;
                }
                else if ((nums[i] + nums[left] + nums[right]) < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return result;
    }
};
// @lc code=end
