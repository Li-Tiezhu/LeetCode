#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>

using namespace std;

/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (st.empty()) {
                st.push(s[i]);
            }
            else if (st.top() == s[i]) {
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }

        string ret;

        while (!st.empty()){
            ret += st.top();
            st.pop();
        }
        reverse(ret.begin(), ret.end());

        return ret;
    }
};










// @lc code=end
