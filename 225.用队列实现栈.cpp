#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;
/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    queue<int> stIn;
    queue<int> stOut;
    MyStack() {

    }

    void push(int x) {
        if (stIn.empty()) {
            stOut.push(x);
        }
        else {
            stIn.push(x);
        }
    }

    int pop() {
        queue<int> *in, *out;

        if (stIn.empty()) {
            in = &stIn;
            out = &stOut;
        }
        else {
            in = &stOut;
            out = &stIn;
        }
        int result;
        while (!out->empty()) {
            result = out->front();
            out->pop();
            if (out->empty()) {
                break;
            }
            in->push(result);
        }
        return result;
    }

    int top() {
        if (stIn.empty()) {
            return stOut.back();
        }
        else {
            return stIn.back();
        }

    }

    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
