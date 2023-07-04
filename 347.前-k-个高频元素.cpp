#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    class myComparison {
    public:
        bool operator()(const pair<int, int> &lhs,const pair<int, int> &rhs) {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 统计元素出现频率
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // 使用小顶堆进行排序
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComparison> pri_que;
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) {
                pri_que.pop();
            }
        }

        vector<int> ret(k);
        for (int i = k - 1; i >= 0; i--) {
            ret[i] = pri_que.top().first;
            pri_que.pop();
        }

        return ret;
    }
};
// @lc code=end
