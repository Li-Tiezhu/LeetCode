#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>

using namespace std;

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> left;
        for (int i = 0; i < s.size(); i++) {
           if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                left.push(s[i]);
           }
           else {
                if (left.empty()) {
                    return false;
                }
                if ((s[i] == ')' && left.top() == '(') ||
                    (s[i] == ']' && left.top() == '[') ||
                    (s[i] == '}' && left.top() == '{') ) {
                    left.pop();
                }
                else {
                    return false;
                }
           }
        }
        if (left.empty()) {
            return true;
        }
        else {
            return false;
        }

    }
};
// @lc code=end
