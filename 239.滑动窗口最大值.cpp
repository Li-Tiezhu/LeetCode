#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <deque>

using namespace std;

/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        deque<int> qu;

        // 处理第一个框
        for (int i = 0; i < k; i++) {
            while ((!qu.empty()) && qu.back() < nums[i]) {
                qu.pop_back();
            }
            qu.push_back(nums[i]);
        }

        ret.push_back(qu.front());

        for (int i = k; i < nums.size(); i++) {
            // ---------pop_back-----------
            if (qu.front() == nums[i - k]) {
                qu.pop_front();
            }
            // ---------push-----------
            while ((!qu.empty()) && qu.back() < nums[i]) {
                qu.pop_back();
            }
            qu.push_back(nums[i]);
            // ---------ret_push-----------
            ret.push_back(qu.front());
        }

        return ret;
    }
};
// @lc code=end
