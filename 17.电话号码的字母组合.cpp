/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<string> character = vector<string>({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});

    vector<string> result;
    string curString;
    int index;

    void backstracking(string digits, int cur) {
        if (cur == digits.size()) {
            result.push_back(curString);
            return;
        }

        index = digits[cur] - '0';
        for (int i = 0; i < character[index].size(); i++) {
            curString.push_back(character[index][i]);
            backstracking(digits, cur + 1);
            curString.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        backstracking(digits, 0);
        return result;
    }
};
// @lc code=end
