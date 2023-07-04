/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int maxDepth(TreeNode* root, int depth) {
        if (root == nullptr)
            return depth;
        int left = maxDepth(root->left, depth + 1);
        if (left == -1) {
            return -1;
        }
        int right = maxDepth(root->right, depth + 1);
        if (right == -1) {
            return -1;
        }
        if (left > right) {
            if (left - right > 1) {
                return -1;
            }
            else {
                return left;
            }
        }
        else {
            if (right - left > 1) {
                return -1;
            }
            else {
                return right;
            }
        }
    }
    bool isBalanced(TreeNode* root) {
        int result = maxDepth(root, 0);
        if (result == -1)
            return false;
        else
            return true;
    }
};
// @lc code=end
