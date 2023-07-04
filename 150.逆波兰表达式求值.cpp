#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>

using namespace std;

/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int trans(string s) {
        int ret = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i == 0 && s[i] == '-') {
                continue;
            }
            ret = ret*10 + (s[i] - '0');
        }
        if (s[0] == '-') {
            ret = -1 * ret;
        }
        return ret;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int a, b;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();

                switch (tokens[i][0]) {
                    case '+': st.push(a + b); break;
                    case '-': st.push(a - b); break;
                    case '*': st.push(a * b); break;
                    case '/': st.push(a / b); break;
                }
            }
            else {
                st.push(trans(tokens[i]));
            }
        }

        return st.top();
    }
};
// @lc code=end
