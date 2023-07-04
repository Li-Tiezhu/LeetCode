/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // static bool cmp(const vector<int> &a, const vector<int> &b) {
    //     return a[1] < b[1];
    // }

    // int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    //     int result = 1, end;
    //     sort(intervals.begin(), intervals.end(), cmp);
    //     end = intervals[0][1];
    //     for (int i = 1; i < intervals.size(); i++) {
    //         if (end <= intervals[i][0]) {
    //             end = intervals[i][1];
    //             result++;
    //         }
    //     }
    //     return intervals.size() - result;
    // }

    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    }

    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 0;
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (end <= intervals[i][0])
                end = intervals[i][1];
            else {
                end = min(end, intervals[i][1]);
                count++;
            }
        }

        return count;
    }
};
// @lc code=end
