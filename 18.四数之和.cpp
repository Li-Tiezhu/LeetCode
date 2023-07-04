#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;
/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0 && nums[i] > target) {
                break;
            }
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            for (int j = i + 1; j < nums.size(); j++) {
                if ((nums[i] + nums[j] > target) && (nums[i] + nums[j] >= 0)) {
                    break;
                }
                if (j > i + 1 && nums[j - 1] == nums[j]) {
                    continue;
                }   
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left + 1] == nums[left]) {
                            left++;
                        }
                        while (left < right && nums[right - 1] == nums[right]) {
                            right--;
                        }
                        left++;
                        right--;
                    }
                    else if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target) {
                        right--;
                    }
                    else {
                        left++;
                    }
                }
            }
        }

        return result;
    }
};
// @lc code=end
