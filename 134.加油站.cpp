/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
#include <iostream>
#include <vector>
// #include <limits.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 方法一
        // int curSum = 0;
        // int min = INT32_MAX;
        // for (int i = 0; i < gas.size(); i++) {
        //     int rest = cost[i] - gas[i];
        //     curSum += rest;
        //     if (curSum < min) {
        //         min = curSum;
        //     }
        // }
        // if (curSum < 0) return -1;  // 总的累加起来是负的，肯定不够
        // if (min > 0) return 0;  // 最小得差值都是正的，说明每一步都有剩余
        //
        // for (int i = gas.size() - 1; i >= 0; i++) {
        //     int rest = gas[i] - cost[i];
        //     min += rest;  // min保留的是历史总的不足，只要从后往前有个位置可以把前面的差值全部弥补，那么从该位置开始就可以
        //     if (rest >= 0) {
        //         return i;
        //     }
        // }
        //
        // return -1;

        // 方法二
        int curSum = 0, start = 0, totalSum = 0;
        for (int i = 0; i < gas.size(); i++) {
            int rest = gas[i] - cost[i];
            curSum += rest;
            totalSum += rest;
            if (curSum < 0) {
                start = i + 1;
                curSum = 0;
            }
        }
        if (totalSum < 0)
            return -1;

        return start;
    }
};
// @lc code=end
