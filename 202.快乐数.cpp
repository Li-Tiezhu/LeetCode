#include <unordered_set>
using namespace std;

/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    int getNum(int num) {
        int ret = 0;
        while (num != 0) {
            ret += (num % 10) * (num % 10);
            num /= 10;
        }
        return ret;
    }
    bool isHappy(int n) {
        unordered_set<int> alrady;

        while (1) {
            n = getNum(n);
            if (n == 1) {
                return true;
            }

            if( alrady.find(n) != alrady.end()) {
                return false;
            }
            alrady.insert(n);
        }

    }
};
// @lc code=end
