#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int min = 0, max = nums.size()-1, tmp = 0;
        while(min <= max) {
            tmp = nums[(max+min)/2];
            if (target == tmp) {
                return (max+min)/2;
            }
            else if(target > tmp) {
                min = (max + min) / 2 + 1;
            }
            else {
                max = (max + min) / 2 - 1;
            }
        }

        return -1;
    }
};
// @lc code=end
