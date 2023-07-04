#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;
/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        int left, right, start, end;
        left = 0;
        right = 2 * k - 1;

        while (left < s.size()) {
            if (right >= s.size()) {
                if ((s.size() - left) < k) {
                    end = s.size() - 1;
                }
                else {
                    end = left + k - 1;
                }
            }
            else {
                end = left + k - 1;
            }

            start = left;

            while (start < end) {
                swap(s[start], s[end]);
                start++;
                end--;
            }
            left += 2 * k;
            right += 2 * k;
        }

        return s;
    }
};
// @lc code=end
