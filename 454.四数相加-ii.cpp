#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;
/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count = 0;
        unordered_map<int, int> umap;
        for (int a : nums1) {
            for (int b : nums2) {
                umap[a+b]++;
            }
        }
        for (int c : nums3) {
            for (int d : nums4) {
                if (umap.find(0 - (c + d)) != umap.end()) {
                    count+= umap[0 - ( c + d)];
                }
            }
        }

        return count;
    }
};
// @lc code=end
