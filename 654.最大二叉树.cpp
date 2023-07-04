/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) {
            return nullptr;
        }
        if (nums.size() == 1) {
            return new TreeNode(nums[0]);
        }
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums[max]) {
                max = i;
            }
        }

        TreeNode *root = new TreeNode(nums[max]);
        vector<int> leftNums(nums.begin(), nums.begin() + max);
        root->left = constructMaximumBinaryTree(leftNums);
        vector<int> rightNums(nums.begin() + max + 1, nums.begin());
        root->right = constructMaximumBinaryTree(rightNums);

        return root;
    }
};
// @lc code=end
