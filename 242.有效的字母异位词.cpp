#include <iostream>
#include <string>

using namespace std;

/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int sSize = s.size(), tSize = t.size();
        int record[26] = {0};

        if (sSize != tSize) {
            return false;
        }
        for (int i = 0; i < sSize; i++) {
            record[s[i] - 'a']++;
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if(record[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
