/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> partitionLabels(string s) {
        int hash[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a'] = i;
        }
        int end = 0, curNum = 0;
        vector<int> result;
        for (int i = 0; i < s.size(); i++) {
            if (end < hash[s[i] - 'a']) end = hash[s[i] - 'a'];
            curNum++;
            if (i == end) {
                result.push_back(curNum);
                curNum = 0;
                continue;
            }
        }

        return result;
    }
};
// @lc code=end
