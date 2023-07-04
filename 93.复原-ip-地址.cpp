/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
#include <iostream>
#include <type_traits>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> result;
    string curString;

    void pushInt(int number) {
        if (number == 0) {
            curString.push_back('0');
            return;
        }
        if (number > 99) {
            curString.push_back(number/100 + '0');
            curString.push_back((number%100)/10 + '0');
            curString.push_back(number%10 + '0');
        }
        else if (number > 9) {
            curString.push_back(number/10 + '0');
            curString.push_back(number%10 + '0');
        }
        else {
            curString.push_back(number + '0');
        }
    }

    void popInt(int number) {
        if (number > 99) {
            curString.pop_back(); curString.pop_back(); curString.pop_back();
        }
        else if (number > 9) {
            curString.pop_back(); curString.pop_back();
        }
        else {
            curString.pop_back();
        }
    }

    void backstracking(string &s, int n, int start) {
        if (n == 5) {
            result.push_back(curString);
            return;
        }
        // NOTE: 不只是判断后面b是不是太多了，还要判断后面的是不是不够了
        if ((s.size() - start) > (3 * (4 - n + 1)) || (s.size() - start) < (4 - n + 1))
        {
            return;
        }

        int myNum = 0;
        if (n == 4) {  // NOTE:对于最后一段只能全部加上，不能一位一位累加
            for (int i = start; i < s.size(); i++) {
                if (i > start && s[start] == '0') {  // NOTE: 需要判断0开始为情况
                    return;
                }
                myNum = myNum * 10 + (s[i] - '0');
            }
            if (myNum > 255) return;
            curString.push_back('.');
            pushInt(myNum);
            backstracking(s, n + 1, 0);
            popInt(myNum);
            curString.pop_back();
        }
        else {
            for (int i = 0; i < 3; i++) {
                if (i > 0 && s[start] == '0') {
                    return;
                }
                myNum = myNum * 10 + (s[start + i] - '0');
                if (myNum > 255) {
                    break;
                }
                if (n > 1) {
                    curString.push_back('.');
                }
                pushInt(myNum);
                backstracking(s, n + 1, start + i + 1);  // NOTE:这里不要忘了+start
                popInt(myNum);
                if (n > 1) {
                    curString.pop_back();
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        backstracking(s, 1, 0);
        return result;
    }
};
// @lc code=end
