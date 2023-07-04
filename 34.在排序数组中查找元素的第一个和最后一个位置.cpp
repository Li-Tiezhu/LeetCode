#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size(), middle;
        vector<int> ret;
        if (right == 0) {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        while (left <= right) {
            middle = (left + right) / 2;
            if (nums[middle] > target) {
                right = middle - 1;
                if(left < 0 || right >= nums.size()) {
                    break;
                }
            }
            else if(nums[middle] < target) {
                left = middle + 1;
                if (left < 0 || right >= nums.size()) {
                    break;
                }
            }
            else {
                left = middle;
                right = middle;
                while(nums[left] == target) {
                    left--;
                    if(left < 0){
                        break;
                    }
                }
                left++;
                ret.push_back(left);
                while(nums[right] == target) {
                    right++;
                    if(right >= nums.size()) {
                        break;
                    }
                }
                right--;
                ret.push_back(right);
                return ret;
            }
        }

        ret.push_back(-1);
        ret.push_back(-1);
        return ret;

        // 二分法，分别查找左右边界
        int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);

        if (leftBorder == -2 || rightBorder == -2) {
            return {-1, -1};
        }
        if ((rightBorder - leftBorder) > 1) {
            return {leftBorder + 1, rightBorder - 1};
        }
        return {-1, -1};
    }
private:
    // 二分法，分别查找左右边界
    int getRightBorder(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, middle;

        // 查找右边界
        int rightBoard = -2;
        while (left <= right) {
            middle = (left + right) / 2;
            if (nums[middle] > target) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
                rightBoard = left;
            }
        }
        return rightBoard;
    }
    // 查找左边界
    int getLeftBorder(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, middle;

        int leftBorder = -2;
        while (left <= right) {
            middle = left + ((right - left) / 2);
            if (nums[middle] < target) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
                leftBorder = right;
            }
        }
        return leftBorder;
    }
};
// @lc code=end
