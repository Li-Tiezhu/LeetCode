/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    vector<string> curString;

    bool judge(string s) {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void backstracking(string &s, int start) {
        if (start == s.size()) {
            result.push_back(curString);
        }
        string myString = "";  // NOTE:逐步增加
        bool isHui;
        for (int i = start; i < s.size(); i++) {
            // NOTE:如果是这种方式生成myString的话需要再在末端+1
            // myString = string(s.begin() + start, s.begin() + i + 1);
            myString.push_back(s[i]);
            isHui = judge(myString);
            if (isHui == true) {
                curString.push_back(myString);
                backstracking(s, i + 1);
                curString.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backstracking(s, 0);
        return result;
    }
};
// @lc code=end
