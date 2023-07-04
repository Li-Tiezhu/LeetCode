/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> result;
    unordered_map<string, map<string, int>> targets;

    bool backtracking(int ticketNum) {
        if (result.size() == ticketNum + 1) {
            return true;
        }

        for (pair<const string, int> &target : targets[result[result.size() - 1]]) {
            if (target.second > 0) {
                result.push_back(target.first);
                target.second--;
                if (backtracking(ticketNum))
                    return true;
                result.pop_back();
                target.second++;
            }
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        targets.clear();
        for (const vector<string> &vec : tickets) {
            targets[vec[0]][vec[1]]++;
        }
        result.push_back("JFK");
        backtracking(tickets.size());
        return result;
    }
};
// @lc code=end
