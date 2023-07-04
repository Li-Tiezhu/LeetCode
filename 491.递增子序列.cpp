#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> curNum;

    void backstracking(vector<int> &nums, int start, int before) {
        if (curNum.size() >= 2) {
            result.push_back(curNum);
        }

        // NOTE: 题目中数字的范围为[-100, 100]，因此可以使用数组来做哈希，提高速度
        // unordered_set<int> st;

        int used[201] = {0};
        for (int i = start; i < nums.size(); i++) {
            if (curNum.size() != 0 && nums[i] < nums[before]) {
                continue;
            }
            // WARNING:这个题不像之前的题目进行了排序，不能直接判断和前一个是否相同
            // if (i > start && nums[i] == nums[i - 1]) {
            //     continue;
            // }

            // 使用set
            // if (st.find(nums[i]) != st.end()) {
            //     continue;
            // }
            // st.insert(nums[i]);

            // 使用数组
            if (used[nums[i] + 100] == 1) {
                continue;
            }
            used[nums[i] + 100] = 1;
            curNum.push_back(nums[i]);
            backstracking(nums, i + 1, i);
            curNum.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backstracking(nums, 0, 0);
        return result;
    }
};
